cmake_minimum_required(VERSION 3.5)

project(openGL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(OpenGL_GL_PREFERENCE LEGACY)

add_subdirectory(/home/pandurski/Libs/glew-2.1.0/build/cmake build)
include_directories(/home/pandurski/Libs/glew-2.1.0/include)


file(GLOB RES_FILES *.frag *.vert *.glsl)
file(GLOB C_CPP_FILES *.h *.cpp)

add_executable(openGL  ${C_CPP_FILES} ${RES_FILES})

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(GLEW REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS} )
include_directories($(GLEW_INCLUDE_DIRS))

target_link_libraries(openGL ${OPENGL_LIBRARIES})

target_link_libraries(openGL glew ${GLEW_LIBRARIES})
target_link_libraries(openGL glew ${OPENGL_glu_LIBRARY} ${GLEW_LIBRARIES})

target_link_libraries(openGL glfw ${GLFW_LIBRARIES})
target_link_libraries(openGL glfw ${OPENGL_glu_LIBRARY} ${GLFW_LIBRARIES})
