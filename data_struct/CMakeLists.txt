cmake_minimum_required(VERSION 3.5)

project(data_struct LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(SDL2_LIBRARIES C:/SDL2-2.0.12/x86_64-w64-mingw32/lib/)
#set(SDL2_INCLUDE_DIRS C:/SDL2-2.0.12/x86_64-w64-mingw32/include/SDL2/)

include_directories(${SDL2_INCLUDE_DIRS})
link_directories(${SDL2_LIBRARIES})

#set(CMAKE_PREFIX_PATH
#    ${CMAKE_PREFIX_PATH}
#    C:/SDL2-2.0.12/x86_64-w64-mingw32/lib/cmake/SDL2/
#)

find_package(SDL2 REQUIRED)

file(GLOB SOURCES "*.cpp" "*.h")

add_executable(data_struct  ${SOURCES})

target_include_directories(data_struct PUBLIC ${SDL2_INCLUDE_DIRS})
target_link_libraries(data_struct ${SDL2_LIBRARIES})
