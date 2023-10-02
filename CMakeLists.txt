cmake_minimum_required(VERSION 3.26)
project(OnlineStore)

set(CMAKE_CXX_STANDARD 20)

add_executable(OnlineStore main.cpp
        include/Store.h
        src/Store.cpp)
