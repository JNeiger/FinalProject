# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = "D:\Programs\CLion 2017.3.2\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Programs\CLion 2017.3.2\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\School\Homework\ECE_4122\Project\FinalProject

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug

# Include any dependencies generated for this target.
include lib/glfw/tests/CMakeFiles/windows.dir/depend.make

# Include the progress variables for this target.
include lib/glfw/tests/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw/tests/CMakeFiles/windows.dir/flags.make

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj: lib/glfw/tests/CMakeFiles/windows.dir/flags.make
lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj: lib/glfw/tests/CMakeFiles/windows.dir/includes_C.rsp
lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj: ../lib/glfw/tests/windows.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\windows.dir\windows.c.obj   -c D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\tests\windows.c

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\tests\windows.c > CMakeFiles\windows.dir\windows.c.i

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\tests\windows.c -o CMakeFiles\windows.dir\windows.c.s

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj.requires:

.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj.requires

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj.provides: lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj.requires
	$(MAKE) -f lib\glfw\tests\CMakeFiles\windows.dir\build.make lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj.provides.build
.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj.provides

lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj.provides.build: lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj


lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj: lib/glfw/tests/CMakeFiles/windows.dir/flags.make
lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj: lib/glfw/tests/CMakeFiles/windows.dir/includes_C.rsp
lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj: ../lib/glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\windows.dir\__\deps\getopt.c.obj   -c D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\getopt.c

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/getopt.c.i"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\getopt.c > CMakeFiles\windows.dir\__\deps\getopt.c.i

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/getopt.c.s"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\getopt.c -o CMakeFiles\windows.dir\__\deps\getopt.c.s

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.requires:

.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.requires

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.provides: lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.requires
	$(MAKE) -f lib\glfw\tests\CMakeFiles\windows.dir\build.make lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.provides.build
.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.provides

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.provides.build: lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj


lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj: lib/glfw/tests/CMakeFiles/windows.dir/flags.make
lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj: lib/glfw/tests/CMakeFiles/windows.dir/includes_C.rsp
lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj: ../lib/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\windows.dir\__\deps\glad.c.obj   -c D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\glad.c

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/__/deps/glad.c.i"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\glad.c > CMakeFiles\windows.dir\__\deps\glad.c.i

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/__/deps/glad.c.s"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\glad.c -o CMakeFiles\windows.dir\__\deps\glad.c.s

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.requires:

.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.requires

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.provides: lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.requires
	$(MAKE) -f lib\glfw\tests\CMakeFiles\windows.dir\build.make lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.provides.build
.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.provides

lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.provides.build: lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj


# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.obj" \
"CMakeFiles/windows.dir/__/deps/getopt.c.obj" \
"CMakeFiles/windows.dir/__/deps/glad.c.obj"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

lib/glfw/tests/windows.exe: lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj
lib/glfw/tests/windows.exe: lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj
lib/glfw/tests/windows.exe: lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj
lib/glfw/tests/windows.exe: lib/glfw/tests/CMakeFiles/windows.dir/build.make
lib/glfw/tests/windows.exe: lib/glfw/src/libglfw3.a
lib/glfw/tests/windows.exe: lib/glfw/tests/CMakeFiles/windows.dir/linklibs.rsp
lib/glfw/tests/windows.exe: lib/glfw/tests/CMakeFiles/windows.dir/objects1.rsp
lib/glfw/tests/windows.exe: lib/glfw/tests/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable windows.exe"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\windows.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glfw/tests/CMakeFiles/windows.dir/build: lib/glfw/tests/windows.exe

.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/build

lib/glfw/tests/CMakeFiles/windows.dir/requires: lib/glfw/tests/CMakeFiles/windows.dir/windows.c.obj.requires
lib/glfw/tests/CMakeFiles/windows.dir/requires: lib/glfw/tests/CMakeFiles/windows.dir/__/deps/getopt.c.obj.requires
lib/glfw/tests/CMakeFiles/windows.dir/requires: lib/glfw/tests/CMakeFiles/windows.dir/__/deps/glad.c.obj.requires

.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/requires

lib/glfw/tests/CMakeFiles/windows.dir/clean:
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && $(CMAKE_COMMAND) -P CMakeFiles\windows.dir\cmake_clean.cmake
.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/clean

lib/glfw/tests/CMakeFiles/windows.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\School\Homework\ECE_4122\Project\FinalProject D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\tests D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests\CMakeFiles\windows.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw/tests/CMakeFiles/windows.dir/depend

