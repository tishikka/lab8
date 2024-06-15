cmake_minimum_required(VERSION 3.10)
project(voting VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(voting main.cpp HashFunction.cpp)
