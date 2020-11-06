cmake_minimum_required(VERSION 3.5)

project(openGL_win LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(C:/ExternalLibs/glm/)

list(APPEND CMAKE_PREFIX_PATH "C:/ExternalLibs/GLEW")
list(APPEND CMAKE_PREFIX_PATH "C:/ExternalLibs/GLFW")


set(GLEW_LIBRARIES "C:/ExternalLibs/GLEW/lib/Release/x64/")
set(GLEW_INCLUDE_DIRS "C:/ExternalLibs/GLEW/include/")

set(GLFW_LIBRARIES "C:/ExternalLibs/GLEW/")
set(GLFW_INCLUDE_DIRS "C:/ExternalLibs/GLEW/include/")

file(GLOB RES_FILES *.frag *.vert *.glsl)
file(GLOB C_CPP_FILES *.h *.cpp)

add_executable(openGL_win  ${C_CPP_FILES} ${RES_FILES})

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
target_link_libraries(openGL_win ${OPENGL_LIBRARIES})


find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
target_link_libraries(openGL_win glew32 ${GLEW_LIBRARIES})
include_directories(${GLFW_INCLUDE_DIRS})
target_link_libraries(openGL_win glfw3 ${GLFW_LIBRARIES})

target_include_directories(openGL_win PUBLIC "C:/ExternalLibs/")

