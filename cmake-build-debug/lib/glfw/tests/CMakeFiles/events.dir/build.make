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
include lib/glfw/tests/CMakeFiles/events.dir/depend.make

# Include the progress variables for this target.
include lib/glfw/tests/CMakeFiles/events.dir/progress.make

# Include the compile flags for this target's objects.
include lib/glfw/tests/CMakeFiles/events.dir/flags.make

lib/glfw/tests/CMakeFiles/events.dir/events.c.obj: lib/glfw/tests/CMakeFiles/events.dir/flags.make
lib/glfw/tests/CMakeFiles/events.dir/events.c.obj: lib/glfw/tests/CMakeFiles/events.dir/includes_C.rsp
lib/glfw/tests/CMakeFiles/events.dir/events.c.obj: ../lib/glfw/tests/events.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lib/glfw/tests/CMakeFiles/events.dir/events.c.obj"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\events.dir\events.c.obj   -c D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\tests\events.c

lib/glfw/tests/CMakeFiles/events.dir/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/events.c.i"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\tests\events.c > CMakeFiles\events.dir\events.c.i

lib/glfw/tests/CMakeFiles/events.dir/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/events.c.s"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\tests\events.c -o CMakeFiles\events.dir\events.c.s

lib/glfw/tests/CMakeFiles/events.dir/events.c.obj.requires:

.PHONY : lib/glfw/tests/CMakeFiles/events.dir/events.c.obj.requires

lib/glfw/tests/CMakeFiles/events.dir/events.c.obj.provides: lib/glfw/tests/CMakeFiles/events.dir/events.c.obj.requires
	$(MAKE) -f lib\glfw\tests\CMakeFiles\events.dir\build.make lib/glfw/tests/CMakeFiles/events.dir/events.c.obj.provides.build
.PHONY : lib/glfw/tests/CMakeFiles/events.dir/events.c.obj.provides

lib/glfw/tests/CMakeFiles/events.dir/events.c.obj.provides.build: lib/glfw/tests/CMakeFiles/events.dir/events.c.obj


lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: lib/glfw/tests/CMakeFiles/events.dir/flags.make
lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: lib/glfw/tests/CMakeFiles/events.dir/includes_C.rsp
lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj: ../lib/glfw/deps/getopt.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\events.dir\__\deps\getopt.c.obj   -c D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\getopt.c

lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/getopt.c.i"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\getopt.c > CMakeFiles\events.dir\__\deps\getopt.c.i

lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/getopt.c.s"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\getopt.c -o CMakeFiles\events.dir\__\deps\getopt.c.s

lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.requires:

.PHONY : lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.requires

lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.provides: lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.requires
	$(MAKE) -f lib\glfw\tests\CMakeFiles\events.dir\build.make lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.provides.build
.PHONY : lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.provides

lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.provides.build: lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj


lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj: lib/glfw/tests/CMakeFiles/events.dir/flags.make
lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj: lib/glfw/tests/CMakeFiles/events.dir/includes_C.rsp
lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj: ../lib/glfw/deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\events.dir\__\deps\glad.c.obj   -c D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\glad.c

lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/events.dir/__/deps/glad.c.i"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\glad.c > CMakeFiles\events.dir\__\deps\glad.c.i

lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/events.dir/__/deps/glad.c.s"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\deps\glad.c -o CMakeFiles\events.dir\__\deps\glad.c.s

lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj.requires:

.PHONY : lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj.requires

lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj.provides: lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj.requires
	$(MAKE) -f lib\glfw\tests\CMakeFiles\events.dir\build.make lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj.provides.build
.PHONY : lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj.provides

lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj.provides.build: lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj


# Object files for target events
events_OBJECTS = \
"CMakeFiles/events.dir/events.c.obj" \
"CMakeFiles/events.dir/__/deps/getopt.c.obj" \
"CMakeFiles/events.dir/__/deps/glad.c.obj"

# External object files for target events
events_EXTERNAL_OBJECTS =

lib/glfw/tests/events.exe: lib/glfw/tests/CMakeFiles/events.dir/events.c.obj
lib/glfw/tests/events.exe: lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj
lib/glfw/tests/events.exe: lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj
lib/glfw/tests/events.exe: lib/glfw/tests/CMakeFiles/events.dir/build.make
lib/glfw/tests/events.exe: lib/glfw/src/libglfw3.a
lib/glfw/tests/events.exe: lib/glfw/tests/CMakeFiles/events.dir/linklibs.rsp
lib/glfw/tests/events.exe: lib/glfw/tests/CMakeFiles/events.dir/objects1.rsp
lib/glfw/tests/events.exe: lib/glfw/tests/CMakeFiles/events.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable events.exe"
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\events.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/glfw/tests/CMakeFiles/events.dir/build: lib/glfw/tests/events.exe

.PHONY : lib/glfw/tests/CMakeFiles/events.dir/build

lib/glfw/tests/CMakeFiles/events.dir/requires: lib/glfw/tests/CMakeFiles/events.dir/events.c.obj.requires
lib/glfw/tests/CMakeFiles/events.dir/requires: lib/glfw/tests/CMakeFiles/events.dir/__/deps/getopt.c.obj.requires
lib/glfw/tests/CMakeFiles/events.dir/requires: lib/glfw/tests/CMakeFiles/events.dir/__/deps/glad.c.obj.requires

.PHONY : lib/glfw/tests/CMakeFiles/events.dir/requires

lib/glfw/tests/CMakeFiles/events.dir/clean:
	cd /d D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests && $(CMAKE_COMMAND) -P CMakeFiles\events.dir\cmake_clean.cmake
.PHONY : lib/glfw/tests/CMakeFiles/events.dir/clean

lib/glfw/tests/CMakeFiles/events.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\School\Homework\ECE_4122\Project\FinalProject D:\School\Homework\ECE_4122\Project\FinalProject\lib\glfw\tests D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests D:\School\Homework\ECE_4122\Project\FinalProject\cmake-build-debug\lib\glfw\tests\CMakeFiles\events.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lib/glfw/tests/CMakeFiles/events.dir/depend
