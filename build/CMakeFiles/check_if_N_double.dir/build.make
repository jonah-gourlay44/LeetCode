# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/daoai/code/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/daoai/code/test/build

# Include any dependencies generated for this target.
include CMakeFiles/check_if_N_double.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/check_if_N_double.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/check_if_N_double.dir/flags.make

CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o: CMakeFiles/check_if_N_double.dir/flags.make
CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o: ../src/check_if_N_double.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daoai/code/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o -c /home/daoai/code/test/src/check_if_N_double.cpp

CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daoai/code/test/src/check_if_N_double.cpp > CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.i

CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daoai/code/test/src/check_if_N_double.cpp -o CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.s

CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o.requires:

.PHONY : CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o.requires

CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o.provides: CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o.requires
	$(MAKE) -f CMakeFiles/check_if_N_double.dir/build.make CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o.provides.build
.PHONY : CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o.provides

CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o.provides.build: CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o


# Object files for target check_if_N_double
check_if_N_double_OBJECTS = \
"CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o"

# External object files for target check_if_N_double
check_if_N_double_EXTERNAL_OBJECTS =

check_if_N_double: CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o
check_if_N_double: CMakeFiles/check_if_N_double.dir/build.make
check_if_N_double: CMakeFiles/check_if_N_double.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daoai/code/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable check_if_N_double"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/check_if_N_double.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/check_if_N_double.dir/build: check_if_N_double

.PHONY : CMakeFiles/check_if_N_double.dir/build

CMakeFiles/check_if_N_double.dir/requires: CMakeFiles/check_if_N_double.dir/src/check_if_N_double.cpp.o.requires

.PHONY : CMakeFiles/check_if_N_double.dir/requires

CMakeFiles/check_if_N_double.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/check_if_N_double.dir/cmake_clean.cmake
.PHONY : CMakeFiles/check_if_N_double.dir/clean

CMakeFiles/check_if_N_double.dir/depend:
	cd /home/daoai/code/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daoai/code/test /home/daoai/code/test /home/daoai/code/test/build /home/daoai/code/test/build /home/daoai/code/test/build/CMakeFiles/check_if_N_double.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/check_if_N_double.dir/depend
