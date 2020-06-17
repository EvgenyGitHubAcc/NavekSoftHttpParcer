cmake_minimum_required(VERSION 3.5)

project(NavekSoftHttpParcer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NavekSoftHttpParcer main.cpp headers.cpp)

target_link_libraries(NavekSoftHttpParcer)
