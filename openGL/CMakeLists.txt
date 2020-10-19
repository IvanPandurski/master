cmake_minimum_required(VERSION 3.5)

project(openGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(../../../../Downloads/glew-2.1.0/build/cmake build)
include_directories(../../../../Downloads/glew-2.1.0/include)

add_subdirectory(../../../../Downloads/glfw-3.3.2/ glwf-build)
include_directories(../../../../Downloads/glfw-3.3.2/include)

add_executable(openGL main.cpp)

find_package(OpenGL REQUIRED)
include_directories( ${OPENGL_INCLUDE_DIRS} )
target_link_libraries(openGL ${OPENGL_LIBRARIES})

target_link_libraries(openGL glew ${GLEW_LIBRARIES})
target_link_libraries(openGL glew ${OPENGL_glu_LIBRARY} ${GLEW_LIBRARIES})

target_link_libraries(openGL glfw ${GLFW_LIBRARIES})
target_link_libraries(openGL glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})
