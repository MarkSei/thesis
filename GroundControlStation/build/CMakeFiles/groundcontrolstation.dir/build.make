# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.9.4_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.9.4_1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/build

# Include any dependencies generated for this target.
include CMakeFiles/groundcontrolstation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/groundcontrolstation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/groundcontrolstation.dir/flags.make

CMakeFiles/groundcontrolstation.dir/src/main.c.o: CMakeFiles/groundcontrolstation.dir/flags.make
CMakeFiles/groundcontrolstation.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/groundcontrolstation.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/groundcontrolstation.dir/src/main.c.o   -c /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/src/main.c

CMakeFiles/groundcontrolstation.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/groundcontrolstation.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/src/main.c > CMakeFiles/groundcontrolstation.dir/src/main.c.i

CMakeFiles/groundcontrolstation.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/groundcontrolstation.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/src/main.c -o CMakeFiles/groundcontrolstation.dir/src/main.c.s

CMakeFiles/groundcontrolstation.dir/src/main.c.o.requires:

.PHONY : CMakeFiles/groundcontrolstation.dir/src/main.c.o.requires

CMakeFiles/groundcontrolstation.dir/src/main.c.o.provides: CMakeFiles/groundcontrolstation.dir/src/main.c.o.requires
	$(MAKE) -f CMakeFiles/groundcontrolstation.dir/build.make CMakeFiles/groundcontrolstation.dir/src/main.c.o.provides.build
.PHONY : CMakeFiles/groundcontrolstation.dir/src/main.c.o.provides

CMakeFiles/groundcontrolstation.dir/src/main.c.o.provides.build: CMakeFiles/groundcontrolstation.dir/src/main.c.o


# Object files for target groundcontrolstation
groundcontrolstation_OBJECTS = \
"CMakeFiles/groundcontrolstation.dir/src/main.c.o"

# External object files for target groundcontrolstation
groundcontrolstation_EXTERNAL_OBJECTS =

../bin/groundcontrolstation: CMakeFiles/groundcontrolstation.dir/src/main.c.o
../bin/groundcontrolstation: CMakeFiles/groundcontrolstation.dir/build.make
../bin/groundcontrolstation: CMakeFiles/groundcontrolstation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../bin/groundcontrolstation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/groundcontrolstation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/groundcontrolstation.dir/build: ../bin/groundcontrolstation

.PHONY : CMakeFiles/groundcontrolstation.dir/build

CMakeFiles/groundcontrolstation.dir/requires: CMakeFiles/groundcontrolstation.dir/src/main.c.o.requires

.PHONY : CMakeFiles/groundcontrolstation.dir/requires

CMakeFiles/groundcontrolstation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/groundcontrolstation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/groundcontrolstation.dir/clean

CMakeFiles/groundcontrolstation.dir/depend:
	cd /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/build /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/build /Users/masei/Desktop/Study-folder/Thesis/Code/src/GroundControlStation/build/CMakeFiles/groundcontrolstation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/groundcontrolstation.dir/depend

