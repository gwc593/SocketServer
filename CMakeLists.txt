cmake_minimum_required(VERSION 3.9)
project(Socket_listen)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable( Socket_listen src/main.cpp
                src/SocketFunctionsOSX.cpp
                include/SocketFunctionsOSX.hpp
                )