cmake_minimum_required(VERSION 3.5)

project(data_struct LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp" "*.h")

add_executable(data_struct  ${SOURCES})
