# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\17432\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.7846.88\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\17432\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\201.7846.88\bin\cmake\win\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\17432\CLionProjects\ve280\mid

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\17432\CLionProjects\ve280\mid\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex1.dir/flags.make

CMakeFiles/ex1.dir/ex1.cpp.obj: CMakeFiles/ex1.dir/flags.make
CMakeFiles/ex1.dir/ex1.cpp.obj: ../ex1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\17432\CLionProjects\ve280\mid\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex1.dir/ex1.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex1.dir\ex1.cpp.obj -c C:\Users\17432\CLionProjects\ve280\mid\ex1.cpp

CMakeFiles/ex1.dir/ex1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex1.dir/ex1.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\17432\CLionProjects\ve280\mid\ex1.cpp > CMakeFiles\ex1.dir\ex1.cpp.i

CMakeFiles/ex1.dir/ex1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex1.dir/ex1.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\17432\CLionProjects\ve280\mid\ex1.cpp -o CMakeFiles\ex1.dir\ex1.cpp.s

# Object files for target ex1
ex1_OBJECTS = \
"CMakeFiles/ex1.dir/ex1.cpp.obj"

# External object files for target ex1
ex1_EXTERNAL_OBJECTS =

ex1.exe: CMakeFiles/ex1.dir/ex1.cpp.obj
ex1.exe: CMakeFiles/ex1.dir/build.make
ex1.exe: CMakeFiles/ex1.dir/linklibs.rsp
ex1.exe: CMakeFiles/ex1.dir/objects1.rsp
ex1.exe: CMakeFiles/ex1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\17432\CLionProjects\ve280\mid\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex1.dir/build: ex1.exe

.PHONY : CMakeFiles/ex1.dir/build

CMakeFiles/ex1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex1.dir/clean

CMakeFiles/ex1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\17432\CLionProjects\ve280\mid C:\Users\17432\CLionProjects\ve280\mid C:\Users\17432\CLionProjects\ve280\mid\cmake-build-debug C:\Users\17432\CLionProjects\ve280\mid\cmake-build-debug C:\Users\17432\CLionProjects\ve280\mid\cmake-build-debug\CMakeFiles\ex1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex1.dir/depend
