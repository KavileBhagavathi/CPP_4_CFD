cmake_minimum_required(VERSION 3.10)
project(1DLinearConvection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../utils)

set(SOURCES
    1DLinearConv.cpp
    ../utils/utils.cpp
    )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/)
add_executable(1DLinearConvection ${SOURCES})