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
include CMakeFiles/find_disappeared.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/find_disappeared.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/find_disappeared.dir/flags.make

CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o: CMakeFiles/find_disappeared.dir/flags.make
CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o: ../src/find_disappeared_numbers.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/daoai/code/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o -c /home/daoai/code/test/src/find_disappeared_numbers.cpp

CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/daoai/code/test/src/find_disappeared_numbers.cpp > CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.i

CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/daoai/code/test/src/find_disappeared_numbers.cpp -o CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.s

CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o.requires:

.PHONY : CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o.requires

CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o.provides: CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o.requires
	$(MAKE) -f CMakeFiles/find_disappeared.dir/build.make CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o.provides.build
.PHONY : CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o.provides

CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o.provides.build: CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o


# Object files for target find_disappeared
find_disappeared_OBJECTS = \
"CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o"

# External object files for target find_disappeared
find_disappeared_EXTERNAL_OBJECTS =

find_disappeared: CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o
find_disappeared: CMakeFiles/find_disappeared.dir/build.make
find_disappeared: CMakeFiles/find_disappeared.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/daoai/code/test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable find_disappeared"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/find_disappeared.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/find_disappeared.dir/build: find_disappeared

.PHONY : CMakeFiles/find_disappeared.dir/build

CMakeFiles/find_disappeared.dir/requires: CMakeFiles/find_disappeared.dir/src/find_disappeared_numbers.cpp.o.requires

.PHONY : CMakeFiles/find_disappeared.dir/requires

CMakeFiles/find_disappeared.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/find_disappeared.dir/cmake_clean.cmake
.PHONY : CMakeFiles/find_disappeared.dir/clean

CMakeFiles/find_disappeared.dir/depend:
	cd /home/daoai/code/test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/daoai/code/test /home/daoai/code/test /home/daoai/code/test/build /home/daoai/code/test/build /home/daoai/code/test/build/CMakeFiles/find_disappeared.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/find_disappeared.dir/depend

