# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gzq/CLionProjects/MatrixMultiplication

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug

# Include any dependencies generated for this target.
include src/serial/CMakeFiles/pre_transpose.dir/depend.make

# Include the progress variables for this target.
include src/serial/CMakeFiles/pre_transpose.dir/progress.make

# Include the compile flags for this target's objects.
include src/serial/CMakeFiles/pre_transpose.dir/flags.make

src/serial/CMakeFiles/pre_transpose.dir/pre_transpose.c.o: src/serial/CMakeFiles/pre_transpose.dir/flags.make
src/serial/CMakeFiles/pre_transpose.dir/pre_transpose.c.o: ../src/serial/pre_transpose.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/serial/CMakeFiles/pre_transpose.dir/pre_transpose.c.o"
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pre_transpose.dir/pre_transpose.c.o   -c /home/gzq/CLionProjects/MatrixMultiplication/src/serial/pre_transpose.c

src/serial/CMakeFiles/pre_transpose.dir/pre_transpose.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pre_transpose.dir/pre_transpose.c.i"
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gzq/CLionProjects/MatrixMultiplication/src/serial/pre_transpose.c > CMakeFiles/pre_transpose.dir/pre_transpose.c.i

src/serial/CMakeFiles/pre_transpose.dir/pre_transpose.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pre_transpose.dir/pre_transpose.c.s"
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gzq/CLionProjects/MatrixMultiplication/src/serial/pre_transpose.c -o CMakeFiles/pre_transpose.dir/pre_transpose.c.s

# Object files for target pre_transpose
pre_transpose_OBJECTS = \
"CMakeFiles/pre_transpose.dir/pre_transpose.c.o"

# External object files for target pre_transpose
pre_transpose_EXTERNAL_OBJECTS =

bin/pre_transpose: src/serial/CMakeFiles/pre_transpose.dir/pre_transpose.c.o
bin/pre_transpose: src/serial/CMakeFiles/pre_transpose.dir/build.make
bin/pre_transpose: lib/libutils.a
bin/pre_transpose: src/serial/CMakeFiles/pre_transpose.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../bin/pre_transpose"
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pre_transpose.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/serial/CMakeFiles/pre_transpose.dir/build: bin/pre_transpose

.PHONY : src/serial/CMakeFiles/pre_transpose.dir/build

src/serial/CMakeFiles/pre_transpose.dir/clean:
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && $(CMAKE_COMMAND) -P CMakeFiles/pre_transpose.dir/cmake_clean.cmake
.PHONY : src/serial/CMakeFiles/pre_transpose.dir/clean

src/serial/CMakeFiles/pre_transpose.dir/depend:
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gzq/CLionProjects/MatrixMultiplication /home/gzq/CLionProjects/MatrixMultiplication/src/serial /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial/CMakeFiles/pre_transpose.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/serial/CMakeFiles/pre_transpose.dir/depend

