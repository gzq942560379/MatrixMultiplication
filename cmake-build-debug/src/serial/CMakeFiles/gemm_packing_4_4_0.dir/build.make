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
include src/serial/CMakeFiles/gemm_packing_4_4_0.dir/depend.make

# Include the progress variables for this target.
include src/serial/CMakeFiles/gemm_packing_4_4_0.dir/progress.make

# Include the compile flags for this target's objects.
include src/serial/CMakeFiles/gemm_packing_4_4_0.dir/flags.make

src/serial/CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.o: src/serial/CMakeFiles/gemm_packing_4_4_0.dir/flags.make
src/serial/CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.o: ../src/serial/gemm_packing_4_4_0.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/serial/CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.o"
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.o   -c /home/gzq/CLionProjects/MatrixMultiplication/src/serial/gemm_packing_4_4_0.c

src/serial/CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.i"
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/gzq/CLionProjects/MatrixMultiplication/src/serial/gemm_packing_4_4_0.c > CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.i

src/serial/CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.s"
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/gzq/CLionProjects/MatrixMultiplication/src/serial/gemm_packing_4_4_0.c -o CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.s

# Object files for target gemm_packing_4_4_0
gemm_packing_4_4_0_OBJECTS = \
"CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.o"

# External object files for target gemm_packing_4_4_0
gemm_packing_4_4_0_EXTERNAL_OBJECTS =

bin/gemm_packing_4_4_0: src/serial/CMakeFiles/gemm_packing_4_4_0.dir/gemm_packing_4_4_0.c.o
bin/gemm_packing_4_4_0: src/serial/CMakeFiles/gemm_packing_4_4_0.dir/build.make
bin/gemm_packing_4_4_0: lib/libutils.a
bin/gemm_packing_4_4_0: src/serial/CMakeFiles/gemm_packing_4_4_0.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../bin/gemm_packing_4_4_0"
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gemm_packing_4_4_0.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/serial/CMakeFiles/gemm_packing_4_4_0.dir/build: bin/gemm_packing_4_4_0

.PHONY : src/serial/CMakeFiles/gemm_packing_4_4_0.dir/build

src/serial/CMakeFiles/gemm_packing_4_4_0.dir/clean:
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial && $(CMAKE_COMMAND) -P CMakeFiles/gemm_packing_4_4_0.dir/cmake_clean.cmake
.PHONY : src/serial/CMakeFiles/gemm_packing_4_4_0.dir/clean

src/serial/CMakeFiles/gemm_packing_4_4_0.dir/depend:
	cd /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gzq/CLionProjects/MatrixMultiplication /home/gzq/CLionProjects/MatrixMultiplication/src/serial /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial /home/gzq/CLionProjects/MatrixMultiplication/cmake-build-debug/src/serial/CMakeFiles/gemm_packing_4_4_0.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/serial/CMakeFiles/gemm_packing_4_4_0.dir/depend

