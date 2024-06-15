cmake_minimum_required(VERSION 3.10)
project(HashTable)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES main.cpp HashTable.cpp)

add_executable(HashTable ${SOURCES})
