add_library(
    sha256
    src/sha256/sha256.hpp
    src/sha256/sha256.hpp
)

target_include_directories(sha256 PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
