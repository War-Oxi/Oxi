# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.3.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Code\C++\Algorithm\1966_PrinterQueue

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Code\C++\Algorithm\1966_PrinterQueue\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/1966_PrinterQueue.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/1966_PrinterQueue.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/1966_PrinterQueue.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/1966_PrinterQueue.dir/flags.make

CMakeFiles/1966_PrinterQueue.dir/main.cpp.obj: CMakeFiles/1966_PrinterQueue.dir/flags.make
CMakeFiles/1966_PrinterQueue.dir/main.cpp.obj: C:/Code/C++/Algorithm/1966_PrinterQueue/main.cpp
CMakeFiles/1966_PrinterQueue.dir/main.cpp.obj: CMakeFiles/1966_PrinterQueue.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Code\C++\Algorithm\1966_PrinterQueue\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/1966_PrinterQueue.dir/main.cpp.obj"
	"C:\PROGRA~1\JetBrains\CLion 2021.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/1966_PrinterQueue.dir/main.cpp.obj -MF CMakeFiles\1966_PrinterQueue.dir\main.cpp.obj.d -o CMakeFiles\1966_PrinterQueue.dir\main.cpp.obj -c C:\Code\C++\Algorithm\1966_PrinterQueue\main.cpp

CMakeFiles/1966_PrinterQueue.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/1966_PrinterQueue.dir/main.cpp.i"
	"C:\PROGRA~1\JetBrains\CLion 2021.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Code\C++\Algorithm\1966_PrinterQueue\main.cpp > CMakeFiles\1966_PrinterQueue.dir\main.cpp.i

CMakeFiles/1966_PrinterQueue.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/1966_PrinterQueue.dir/main.cpp.s"
	"C:\PROGRA~1\JetBrains\CLion 2021.3.3\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Code\C++\Algorithm\1966_PrinterQueue\main.cpp -o CMakeFiles\1966_PrinterQueue.dir\main.cpp.s

# Object files for target 1966_PrinterQueue
1966_PrinterQueue_OBJECTS = \
"CMakeFiles/1966_PrinterQueue.dir/main.cpp.obj"

# External object files for target 1966_PrinterQueue
1966_PrinterQueue_EXTERNAL_OBJECTS =

1966_PrinterQueue.exe: CMakeFiles/1966_PrinterQueue.dir/main.cpp.obj
1966_PrinterQueue.exe: CMakeFiles/1966_PrinterQueue.dir/build.make
1966_PrinterQueue.exe: CMakeFiles/1966_PrinterQueue.dir/linklibs.rsp
1966_PrinterQueue.exe: CMakeFiles/1966_PrinterQueue.dir/objects1.rsp
1966_PrinterQueue.exe: CMakeFiles/1966_PrinterQueue.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Code\C++\Algorithm\1966_PrinterQueue\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 1966_PrinterQueue.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\1966_PrinterQueue.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/1966_PrinterQueue.dir/build: 1966_PrinterQueue.exe
.PHONY : CMakeFiles/1966_PrinterQueue.dir/build

CMakeFiles/1966_PrinterQueue.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\1966_PrinterQueue.dir\cmake_clean.cmake
.PHONY : CMakeFiles/1966_PrinterQueue.dir/clean

CMakeFiles/1966_PrinterQueue.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Code\C++\Algorithm\1966_PrinterQueue C:\Code\C++\Algorithm\1966_PrinterQueue C:\Code\C++\Algorithm\1966_PrinterQueue\cmake-build-debug C:\Code\C++\Algorithm\1966_PrinterQueue\cmake-build-debug C:\Code\C++\Algorithm\1966_PrinterQueue\cmake-build-debug\CMakeFiles\1966_PrinterQueue.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/1966_PrinterQueue.dir/depend

