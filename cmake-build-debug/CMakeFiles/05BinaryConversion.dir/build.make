# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\Code\C&C++\78DataStructure"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\Code\C&C++\78DataStructure\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/05BinaryConversion.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/05BinaryConversion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/05BinaryConversion.dir/flags.make

CMakeFiles/05BinaryConversion.dir/05BinaryConversion.cpp.obj: CMakeFiles/05BinaryConversion.dir/flags.make
CMakeFiles/05BinaryConversion.dir/05BinaryConversion.cpp.obj: ../05BinaryConversion.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\Code\C&C++\78DataStructure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/05BinaryConversion.dir/05BinaryConversion.cpp.obj"
	D:\CodeEnvironment\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\05BinaryConversion.dir\05BinaryConversion.cpp.obj -c "D:\Code\C&C++\78DataStructure\05BinaryConversion.cpp"

CMakeFiles/05BinaryConversion.dir/05BinaryConversion.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/05BinaryConversion.dir/05BinaryConversion.cpp.i"
	D:\CodeEnvironment\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\Code\C&C++\78DataStructure\05BinaryConversion.cpp" > CMakeFiles\05BinaryConversion.dir\05BinaryConversion.cpp.i

CMakeFiles/05BinaryConversion.dir/05BinaryConversion.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/05BinaryConversion.dir/05BinaryConversion.cpp.s"
	D:\CodeEnvironment\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\Code\C&C++\78DataStructure\05BinaryConversion.cpp" -o CMakeFiles\05BinaryConversion.dir\05BinaryConversion.cpp.s

# Object files for target 05BinaryConversion
05BinaryConversion_OBJECTS = \
"CMakeFiles/05BinaryConversion.dir/05BinaryConversion.cpp.obj"

# External object files for target 05BinaryConversion
05BinaryConversion_EXTERNAL_OBJECTS =

05BinaryConversion.exe: CMakeFiles/05BinaryConversion.dir/05BinaryConversion.cpp.obj
05BinaryConversion.exe: CMakeFiles/05BinaryConversion.dir/build.make
05BinaryConversion.exe: CMakeFiles/05BinaryConversion.dir/linklibs.rsp
05BinaryConversion.exe: CMakeFiles/05BinaryConversion.dir/objects1.rsp
05BinaryConversion.exe: CMakeFiles/05BinaryConversion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\Code\C&C++\78DataStructure\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 05BinaryConversion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\05BinaryConversion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/05BinaryConversion.dir/build: 05BinaryConversion.exe
.PHONY : CMakeFiles/05BinaryConversion.dir/build

CMakeFiles/05BinaryConversion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\05BinaryConversion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/05BinaryConversion.dir/clean

CMakeFiles/05BinaryConversion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\Code\C&C++\78DataStructure" "D:\Code\C&C++\78DataStructure" "D:\Code\C&C++\78DataStructure\cmake-build-debug" "D:\Code\C&C++\78DataStructure\cmake-build-debug" "D:\Code\C&C++\78DataStructure\cmake-build-debug\CMakeFiles\05BinaryConversion.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/05BinaryConversion.dir/depend

