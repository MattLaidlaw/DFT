cmake_minimum_required(VERSION 3.22)
project(DFT)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(extern)
add_subdirectory(sources)

enable_testing()
add_subdirectory(tests)
