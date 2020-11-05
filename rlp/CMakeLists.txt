add_library(
    rlp
    src/rlp/items/rlpstring.hpp
    src/rlp/items/rlpstring.cpp
    src/rlp/items/rlplist.hpp
    src/rlp/items/rlplist.cpp
    src/rlp/codec/rlpencode.hpp
    src/rlp/codec/rlpencode.cpp
    src/rlp/codec/rlpdecode.hpp
    src/rlp/codec/rlpdecode.cpp
)

target_include_directories(rlp PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(rlp PRIVATE constants utils)
