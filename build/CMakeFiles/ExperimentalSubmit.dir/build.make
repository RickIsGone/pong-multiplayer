# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\cmake-3.28.0-rc1-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = C:\cmake-3.28.0-rc1-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\ricca\Desktop\informatica\pong multiplayer"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\ricca\Desktop\informatica\pong multiplayer\build"

# Utility rule file for ExperimentalSubmit.

# Include any custom commands dependencies for this target.
include CMakeFiles\ExperimentalSubmit.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\ExperimentalSubmit.dir\progress.make

CMakeFiles\ExperimentalSubmit:
	C:\cmake-3.28.0-rc1-windows-x86_64\bin\ctest.exe -D ExperimentalSubmit

ExperimentalSubmit: CMakeFiles\ExperimentalSubmit
ExperimentalSubmit: CMakeFiles\ExperimentalSubmit.dir\build.make
.PHONY : ExperimentalSubmit

# Rule to build all files generated by this target.
CMakeFiles\ExperimentalSubmit.dir\build: ExperimentalSubmit
.PHONY : CMakeFiles\ExperimentalSubmit.dir\build

CMakeFiles\ExperimentalSubmit.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ExperimentalSubmit.dir\cmake_clean.cmake
.PHONY : CMakeFiles\ExperimentalSubmit.dir\clean

CMakeFiles\ExperimentalSubmit.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" "C:\Users\ricca\Desktop\informatica\pong multiplayer" "C:\Users\ricca\Desktop\informatica\pong multiplayer" "C:\Users\ricca\Desktop\informatica\pong multiplayer\build" "C:\Users\ricca\Desktop\informatica\pong multiplayer\build" "C:\Users\ricca\Desktop\informatica\pong multiplayer\build\CMakeFiles\ExperimentalSubmit.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles\ExperimentalSubmit.dir\depend

