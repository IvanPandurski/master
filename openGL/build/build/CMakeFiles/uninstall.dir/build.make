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

# Utility rule file for uninstall.

# Include the progress variables for this target.
include build/CMakeFiles/uninstall.dir/progress.make

build/CMakeFiles/uninstall:
	cd /home/pandurski/workspace/master/openGL/build/build && /usr/bin/cmake -P /home/pandurski/workspace/master/openGL/build/build/cmake_uninstall.cmake

uninstall: build/CMakeFiles/uninstall
uninstall: build/CMakeFiles/uninstall.dir/build.make

.PHONY : uninstall

# Rule to build all files generated by this target.
build/CMakeFiles/uninstall.dir/build: uninstall

.PHONY : build/CMakeFiles/uninstall.dir/build

build/CMakeFiles/uninstall.dir/clean:
	cd /home/pandurski/workspace/master/openGL/build/build && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : build/CMakeFiles/uninstall.dir/clean

build/CMakeFiles/uninstall.dir/depend:
	cd /home/pandurski/workspace/master/openGL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pandurski/workspace/master/openGL /home/pandurski/Libs/glew-2.1.0/build/cmake /home/pandurski/workspace/master/openGL/build /home/pandurski/workspace/master/openGL/build/build /home/pandurski/workspace/master/openGL/build/build/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : build/CMakeFiles/uninstall.dir/depend

