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
CMAKE_SOURCE_DIR = C:\Users\17432\CLionProjects\ve280\mid\ex1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\17432\CLionProjects\ve280\mid\ex1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex2.dir/flags.make

CMakeFiles/ex2.dir/selectMod.cpp.obj: CMakeFiles/ex2.dir/flags.make
CMakeFiles/ex2.dir/selectMod.cpp.obj: ../selectMod.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\17432\CLionProjects\ve280\mid\ex1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex2.dir/selectMod.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex2.dir\selectMod.cpp.obj -c C:\Users\17432\CLionProjects\ve280\mid\ex1\selectMod.cpp

CMakeFiles/ex2.dir/selectMod.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.dir/selectMod.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\17432\CLionProjects\ve280\mid\ex1\selectMod.cpp > CMakeFiles\ex2.dir\selectMod.cpp.i

CMakeFiles/ex2.dir/selectMod.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.dir/selectMod.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\17432\CLionProjects\ve280\mid\ex1\selectMod.cpp -o CMakeFiles\ex2.dir\selectMod.cpp.s

CMakeFiles/ex2.dir/recursive.cpp.obj: CMakeFiles/ex2.dir/flags.make
CMakeFiles/ex2.dir/recursive.cpp.obj: ../recursive.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\17432\CLionProjects\ve280\mid\ex1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ex2.dir/recursive.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex2.dir\recursive.cpp.obj -c C:\Users\17432\CLionProjects\ve280\mid\ex1\recursive.cpp

CMakeFiles/ex2.dir/recursive.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2.dir/recursive.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\17432\CLionProjects\ve280\mid\ex1\recursive.cpp > CMakeFiles\ex2.dir\recursive.cpp.i

CMakeFiles/ex2.dir/recursive.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2.dir/recursive.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\17432\CLionProjects\ve280\mid\ex1\recursive.cpp -o CMakeFiles\ex2.dir\recursive.cpp.s

# Object files for target ex2
ex2_OBJECTS = \
"CMakeFiles/ex2.dir/selectMod.cpp.obj" \
"CMakeFiles/ex2.dir/recursive.cpp.obj"

# External object files for target ex2
ex2_EXTERNAL_OBJECTS =

ex2.exe: CMakeFiles/ex2.dir/selectMod.cpp.obj
ex2.exe: CMakeFiles/ex2.dir/recursive.cpp.obj
ex2.exe: CMakeFiles/ex2.dir/build.make
ex2.exe: CMakeFiles/ex2.dir/linklibs.rsp
ex2.exe: CMakeFiles/ex2.dir/objects1.rsp
ex2.exe: CMakeFiles/ex2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\17432\CLionProjects\ve280\mid\ex1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ex2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex2.dir/build: ex2.exe

.PHONY : CMakeFiles/ex2.dir/build

CMakeFiles/ex2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex2.dir/clean

CMakeFiles/ex2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\17432\CLionProjects\ve280\mid\ex1 C:\Users\17432\CLionProjects\ve280\mid\ex1 C:\Users\17432\CLionProjects\ve280\mid\ex1\cmake-build-debug C:\Users\17432\CLionProjects\ve280\mid\ex1\cmake-build-debug C:\Users\17432\CLionProjects\ve280\mid\ex1\cmake-build-debug\CMakeFiles\ex2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex2.dir/depend
