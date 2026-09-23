#include <gtest/gtest.h>
#include <sys/socket.h>
#include <unistd.h>
#include <atomic>
#include <chrono>
#include <thread>
#include <vector>

#include "structs.h"
#include "SpecialBufferStructs.h"
#include "connection/connection.h"
#include "spdlogDriver/Logger.h"

static std::vector<uint8_t> makePacket(uint32_t size)
{
    std::vector<uint8_t> pkt(size, 0);
    RequestResponseHeader h{};
    h.setSize(size);
    h.setType(35);
    memcpy(pkt.data(), &h, sizeof(h));
    return pkt;
}

TEST(MutexRoundBuffer, EnqueueTimesOutWhenFull)
{
    MutexRoundBuffer rb(1024);
    auto pkt = makePacket(800);
    ASSERT_TRUE(rb.EnqueuePacket(pkt.data(), 100));
    auto t0 = std::chrono::steady_clock::now();
    EXPECT_FALSE(rb.EnqueuePacket(pkt.data(), 100));
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t0).count();
    EXPECT_GE(ms, 90);
    EXPECT_LT(ms, 2000);
}

TEST(MutexRoundBuffer, NotifyStopReleasesBlockedProducer)
{
    MutexRoundBuffer rb(1024);
    auto pkt = makePacket(800);
    ASSERT_TRUE(rb.EnqueuePacket(pkt.data()));
    std::atomic<bool> returned{false};
    std::thread producer([&] {
        EXPECT_FALSE(rb.EnqueuePacket(pkt.data())); // waits forever without stop
        returned = true;
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    EXPECT_FALSE(returned.load());
    rb.notifyStop();
    producer.join();
    EXPECT_TRUE(returned.load());
}

// Reproduces the reqp pool wedge: incoming peer stops reading, then drops.
TEST(QubicConnection, DisconnectReleasesBlockedEnqueueSend)
{
    Logger::init("off"); // sendThread logs on send failure
    int sv[2];
    ASSERT_EQ(socketpair(AF_UNIX, SOCK_STREAM, 0, sv), 0);
    QubicConnection conn(sv[0]); // peer sv[1] never reads

    auto pkt = makePacket(1u << 20);
    std::atomic<bool> done{false};
    std::atomic<int> lastRet{0};
    std::thread producer([&] {
        for (int i = 0; i < 64; i++) // 64MB >> 16MB send buffer
        {
            lastRet = conn.enqueueSend(pkt.data(), (int)pkt.size());
            if (lastRet < 0) break;
        }
        done = true;
    });
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    ASSERT_FALSE(done.load()); // producer is parked on the full buffer
    conn.disconnect();
    auto t0 = std::chrono::steady_clock::now();
    producer.join();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - t0).count();
    EXPECT_LT(ms, 1000);
    EXPECT_EQ(lastRet.load(), -1);
    EXPECT_FALSE(conn.isSocketValid());
    close(sv[1]);
}
