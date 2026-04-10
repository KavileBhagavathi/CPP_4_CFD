cmake_minimum_required(VERSION 3.10)
project(1DNonLinearConvection)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(../utils)

set(SOURCES
    CFL_1DNonLinearConv.cpp
    ../utils/utils.cpp
    )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/)
add_executable(CFL1DNonLinearConvection ${SOURCES})