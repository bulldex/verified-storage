# Verified Storage: Modified Merkle Patricia Trie implementation in C++.
# Copyright 2019-2020 Verified Networks (Kallol Borah).
# Licensed under the MIT License. See the LICENSE file.

# This is a CMake for verified-storage
cmake_minimum_required(VERSION 3.16.0)

# Include Hunter configurations
Include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.257.tar.gz"
    SHA1 "52203b35dfc2f975f4c22fc89f055476726e4288"
)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(verified-storage VERSION 0.1.0)

# Boost Header only library
hunter_add_package(Boost)
find_package(Boost CONFIG REQUIRED)

# Add project specific subdirectories
add_subdirectory(constants)
add_subdirectory(utils)
add_subdirectory(rlp)
add_subdirectory(keccak)
add_subdirectory(storage)
# add_subdirectory(test)

set(SOURCE storage.cpp)
add_executable(vnstorage ${SOURCE})

target_link_libraries(vnstorage PRIVATE constants utils rlp keccak storage)
