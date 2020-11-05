add_library(
    storage
    src/storage/nodes/node.hpp
    src/storage/nodes/node.cpp
    src/storage/nodes/leaf.hpp
    src/storage/nodes/leaf.cpp
    src/storage/nodes/branch.hpp
    src/storage/nodes/branch.cpp
    src/storage/nodes/extension.hpp
    src/storage/nodes/extension.cpp
    src/storage/utils/aliasadvance.hpp
    src/storage/utils/nodeutils.hpp
    src/storage/utils/nodeutils.cpp
    src/storage/utils/batchdbop.hpp
    src/storage/utils/batchdbop.cpp
    src/storage/utils/path.hpp
    src/storage/utils/path.cpp
    src/storage/utils/foundnode.hpp
    src/storage/utils/foundnode.cpp
    src/storage/db/db.hpp
    src/storage/db/db.cpp
    src/storage/core/vtrie.hpp
    src/storage/core/vtrie.cpp
)

target_include_directories(storage PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

# Leveldb library
hunter_add_package(leveldb)
find_package(leveldb CONFIG REQUIRED)

target_link_libraries(storage PRIVATE leveldb::leveldb constants utils rlp keccak)
