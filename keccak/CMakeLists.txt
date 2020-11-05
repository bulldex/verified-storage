add_library(
    keccak
    src/keccak/keccak.h
    src/keccak/keccak.cpp
    src/keccak/keccak_buffer.hpp
    src/keccak/keccak_buffer.cpp
)

target_include_directories(keccak PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

target_link_libraries(keccak PRIVATE constants utils)