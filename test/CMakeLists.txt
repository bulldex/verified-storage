set(SOURCE main.cpp)
add_executable(vntests ${SOURCE})

target_link_libraries(vntests PRIVATE constants utils rlp keccak storage)
