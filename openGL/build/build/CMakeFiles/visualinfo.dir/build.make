# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pandurski/workspace/master/openGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pandurski/workspace/master/openGL/build

# Include any dependencies generated for this target.
include build/CMakeFiles/visualinfo.dir/depend.make

# Include the progress variables for this target.
include build/CMakeFiles/visualinfo.dir/progress.make

# Include the compile flags for this target's objects.
include build/CMakeFiles/visualinfo.dir/flags.make

build/CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.o: build/CMakeFiles/visualinfo.dir/flags.make
build/CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.o: /home/pandurski/Libs/glew-2.1.0/src/visualinfo.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pandurski/workspace/master/openGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object build/CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.o"
	cd /home/pandurski/workspace/master/openGL/build/build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.o   -c /home/pandurski/Libs/glew-2.1.0/src/visualinfo.c

build/CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.i"
	cd /home/pandurski/workspace/master/openGL/build/build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pandurski/Libs/glew-2.1.0/src/visualinfo.c > CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.i

build/CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.s"
	cd /home/pandurski/workspace/master/openGL/build/build && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pandurski/Libs/glew-2.1.0/src/visualinfo.c -o CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.s

# Object files for target visualinfo
visualinfo_OBJECTS = \
"CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.o"

# External object files for target visualinfo
visualinfo_EXTERNAL_OBJECTS =

bin/visualinfo: build/CMakeFiles/visualinfo.dir/home/pandurski/Libs/glew-2.1.0/src/visualinfo.c.o
bin/visualinfo: build/CMakeFiles/visualinfo.dir/build.make
bin/visualinfo: lib/libGLEWd.so.2.1.0
bin/visualinfo: /usr/lib/x86_64-linux-gnu/libX11.so
bin/visualinfo: /usr/lib/x86_64-linux-gnu/libXext.so
bin/visualinfo: /usr/lib/x86_64-linux-gnu/libGL.so
bin/visualinfo: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/visualinfo: build/CMakeFiles/visualinfo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pandurski/workspace/master/openGL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/visualinfo"
	cd /home/pandurski/workspace/master/openGL/build/build && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/visualinfo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
build/CMakeFiles/visualinfo.dir/build: bin/visualinfo

.PHONY : build/CMakeFiles/visualinfo.dir/build

build/CMakeFiles/visualinfo.dir/clean:
	cd /home/pandurski/workspace/master/openGL/build/build && $(CMAKE_COMMAND) -P CMakeFiles/visualinfo.dir/cmake_clean.cmake
.PHONY : build/CMakeFiles/visualinfo.dir/clean

build/CMakeFiles/visualinfo.dir/depend:
	cd /home/pandurski/workspace/master/openGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pandurski/workspace/master/openGL /home/pandurski/Libs/glew-2.1.0/build/cmake /home/pandurski/workspace/master/openGL/build /home/pandurski/workspace/master/openGL/build/build /home/pandurski/workspace/master/openGL/build/build/CMakeFiles/visualinfo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : build/CMakeFiles/visualinfo.dir/depend
