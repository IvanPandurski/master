# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\CMake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\dev\workspace\master\openGL_win

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\dev\workspace\master\openGL_win\build

# Include any dependencies generated for this target.
include CMakeFiles/openGL_win.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/openGL_win.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/openGL_win.dir/flags.make

CMakeFiles/openGL_win.dir/main.cpp.obj: CMakeFiles/openGL_win.dir/flags.make
CMakeFiles/openGL_win.dir/main.cpp.obj: CMakeFiles/openGL_win.dir/includes_CXX.rsp
CMakeFiles/openGL_win.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\dev\workspace\master\openGL_win\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/openGL_win.dir/main.cpp.obj"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\openGL_win.dir\main.cpp.obj -c D:\dev\workspace\master\openGL_win\main.cpp

CMakeFiles/openGL_win.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/openGL_win.dir/main.cpp.i"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\dev\workspace\master\openGL_win\main.cpp > CMakeFiles\openGL_win.dir\main.cpp.i

CMakeFiles/openGL_win.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/openGL_win.dir/main.cpp.s"
	C:\Qt\Tools\mingw810_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\dev\workspace\master\openGL_win\main.cpp -o CMakeFiles\openGL_win.dir\main.cpp.s

# Object files for target openGL_win
openGL_win_OBJECTS = \
"CMakeFiles/openGL_win.dir/main.cpp.obj"

# External object files for target openGL_win
openGL_win_EXTERNAL_OBJECTS =

openGL_win.exe: CMakeFiles/openGL_win.dir/main.cpp.obj
openGL_win.exe: CMakeFiles/openGL_win.dir/build.make
openGL_win.exe: C:/ExternalLibs/GLEW/lib/Release/Win32/glew32.lib
openGL_win.exe: CMakeFiles/openGL_win.dir/linklibs.rsp
openGL_win.exe: CMakeFiles/openGL_win.dir/objects1.rsp
openGL_win.exe: CMakeFiles/openGL_win.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\dev\workspace\master\openGL_win\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable openGL_win.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\openGL_win.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/openGL_win.dir/build: openGL_win.exe

.PHONY : CMakeFiles/openGL_win.dir/build

CMakeFiles/openGL_win.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\openGL_win.dir\cmake_clean.cmake
.PHONY : CMakeFiles/openGL_win.dir/clean

CMakeFiles/openGL_win.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\dev\workspace\master\openGL_win D:\dev\workspace\master\openGL_win D:\dev\workspace\master\openGL_win\build D:\dev\workspace\master\openGL_win\build D:\dev\workspace\master\openGL_win\build\CMakeFiles\openGL_win.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/openGL_win.dir/depend

