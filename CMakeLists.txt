cmake_minimum_required(VERSION 3.20)
project(Pilvi)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(Pilvi main.cpp exceptions/missing_argument_exception.h)
