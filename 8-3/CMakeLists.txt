cmake_minimum_required(VERSION 3.15.0)
project(img VERSION 0.1.0 LANGUAGES C CXX)

find_package(OpenCV REQUIRED)
find_package(OpenSSL REQUIRED)
include_directories(OpenCV_LIBS)
include_directories( ${OPENSSL_INCLUDE_DIR})

add_executable(img main.cpp)

target_link_libraries(img ${OpenCV_LIBS} ${OPENSSL_LIBRARIES})