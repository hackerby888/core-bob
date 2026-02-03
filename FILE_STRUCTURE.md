# Project File Structure

```
.
|-- .clang-format
|-- .dockerignore
|-- .github
|   `-- workflows
|       |-- ci.yml
|       |-- docker-nightly.yml
|       |-- linux-build.yml
|       `-- release.yml
|-- .gitignore
|-- CMakeLists.txt
|-- FILE_STRUCTURE.md
|-- README.md
|-- conf
|   |-- keydb.conf
|   |-- kvrocks.conf
|   `-- kvrocks.service
|-- default_config_bob.json
|-- doc
|   |-- ANATOMY_OF_BOB.MD
|   |-- CONFIG_FILE.MD
|   |-- DEAL_WITH_TX.MD
|   |-- EPOCH_TRANSITION.MD
|   |-- FINDLOG.MD
|   |-- FIND_LOG_ASSET_ADVANCED.MD
|   |-- FIND_LOG_ASSET_EASY.MD
|   |-- INDEXER_INDEXING_DATA.MD
|   |-- KERN_BUF_SIZE.MD
|   |-- KEYDB_INSTALL.md
|   |-- KVROCKS_INSTALL.MD
|   |-- LOGGING_IN_QUBIC.MD
|   |-- LOG_EVENT_STREAM.MD
|   |-- QUBIC_JSON_RPC.md
|   `-- REST_API.md
|-- docker
|   |-- Dockerfile
|   |-- README.md
|   |-- bob.json
|   |-- docker-hub.md
|   |-- entrypoint.sh
|   |-- examples
|   |   |-- docker-compose.yml
|   |   `-- redis.conf
|   |-- keydb.conf
|   |-- kvrocks.conf
|   |-- redis.conf
|   `-- supervisord.conf
|-- external
|   `-- XKCP
|       |-- KangarooTwelve.c
|       |-- KangarooTwelve.h
|       |-- KeccakP-1600-AVX2.h
|       |-- KeccakP-1600-AVX2.s
|       |-- KeccakP-1600-SnP.h
|       |-- KeccakP-1600-times4-AVX2.c
|       |-- KeccakP-1600-times4-AVX2.h
|       |-- KeccakP-1600-times4-SnP.h
|       |-- KeccakP-1600-unrolling.macros
|       |-- KeccakSponge.h
|       |-- KeccakSponge.inc
|       |-- Phases.h
|       |-- PlSnP-common.h
|       |-- SnP-common.h
|       |-- TurboSHAKE.c
|       |-- TurboSHAKE.h
|       |-- align.h
|       |-- brg_endian.h
|       `-- xkcp_config.h
|-- scripts
|   |-- delete_log_id.lua
|   |-- delete_log_ranges.lua
|   |-- delete_tickdata_tickvote.lua
|   |-- set_tracker.lua
|   |-- test_rpc.sh
|   `-- useful_script.sh
|-- src
|   |-- bob.cpp
|   |-- bob.h
|   |-- config.cpp
|   |-- config.h
|   |-- connection
|   |   |-- connection.cpp
|   |   |-- connection.h
|   |   |-- connection_pool.cpp
|   |   |-- node_introducer.cpp
|   |   `-- request_map.h
|   |-- core
|   |   |-- asset.h
|   |   |-- common_def.h
|   |   |-- defines.h
|   |   |-- entity.h
|   |   |-- k12_and_key_util.h
|   |   |-- log_event
|   |   |   |-- log_event.cpp
|   |   |   `-- log_event.h
|   |   |-- m256i.h
|   |   `-- structs.h
|   |-- database
|   |   |-- db.cpp
|   |   |-- db.h
|   |   `-- garbage_cleaner.cpp
|   |-- fs
|   |   |-- file_io.cpp
|   |   `-- file_io.h
|   |-- global_var.cpp
|   |-- global_var.h
|   |-- logger
|   |   |-- logger.cpp
|   |   `-- logger.h
|   |-- main.cpp
|   |-- migrator
|   |   `-- migrator.cpp
|   |-- p2p
|   |   `-- p2p_server.cpp
|   |-- pop10.cpp
|   |-- processors
|   |   |-- indexer
|   |   |   `-- indexer.cpp
|   |   |-- io
|   |   |   `-- io_processor.cpp
|   |   |-- logging
|   |   |   `-- logging_event.cpp
|   |   `-- ticking
|   |       `-- ticking.cpp
|   |-- profiler
|   |   `-- profiler.h
|   |-- rest_api
|   |   |-- ApiHelpers.cpp
|   |   |-- ApiHelpers.h
|   |   |-- LogSubscriptionManager.cpp
|   |   |-- LogSubscriptionManager.h
|   |   |-- LogWebSocket.cpp
|   |   |-- LogWebSocket.h
|   |   |-- QubicRpcHandler.cpp
|   |   |-- QubicRpcHandler.h
|   |   |-- QubicRpcMapper.cpp
|   |   |-- QubicRpcMapper.h
|   |   |-- QubicRpcMethods.cpp
|   |   |-- QubicRpcMethods.h
|   |   |-- QubicRpcWebSocket.cpp
|   |   |-- QubicRpcWebSocket.h
|   |   |-- QubicSubscriptionManager.cpp
|   |   |-- QubicSubscriptionManager.h
|   |   |-- RESTServer.cpp
|   |   |-- bobAPI.cpp
|   |   |-- openapi.json
|   |   `-- querySmartContract.cpp
|   |-- shim.h
|   |-- special_buffer_structs.h
|   |-- utils
|   |   `-- utils.h
|   `-- version.h
|-- tests
|   |-- test_round_buffer.cpp
|   `-- test_xkcp.cpp
`-- web
    `-- rpc_playground.html

29 directories, 128 files
```
