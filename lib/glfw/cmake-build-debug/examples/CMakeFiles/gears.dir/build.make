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
CMAKE_SOURCE_DIR = D:\School\Homework\ECE_4122\HW5\glfw-3.2.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug

# Include any dependencies generated for this target.
include examples/CMakeFiles/gears.dir/depend.make

# Include the progress variables for this target.
include examples/CMakeFiles/gears.dir/progress.make

# Include the compile flags for this target's objects.
include examples/CMakeFiles/gears.dir/flags.make

examples/CMakeFiles/gears.dir/gears.c.obj: examples/CMakeFiles/gears.dir/flags.make
examples/CMakeFiles/gears.dir/gears.c.obj: examples/CMakeFiles/gears.dir/includes_C.rsp
examples/CMakeFiles/gears.dir/gears.c.obj: ../examples/gears.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object examples/CMakeFiles/gears.dir/gears.c.obj"
	cd /d D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\gears.dir\gears.c.obj   -c D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\examples\gears.c

examples/CMakeFiles/gears.dir/gears.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gears.dir/gears.c.i"
	cd /d D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\examples\gears.c > CMakeFiles\gears.dir\gears.c.i

examples/CMakeFiles/gears.dir/gears.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gears.dir/gears.c.s"
	cd /d D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\examples\gears.c -o CMakeFiles\gears.dir\gears.c.s

examples/CMakeFiles/gears.dir/gears.c.obj.requires:

.PHONY : examples/CMakeFiles/gears.dir/gears.c.obj.requires

examples/CMakeFiles/gears.dir/gears.c.obj.provides: examples/CMakeFiles/gears.dir/gears.c.obj.requires
	$(MAKE) -f examples\CMakeFiles\gears.dir\build.make examples/CMakeFiles/gears.dir/gears.c.obj.provides.build
.PHONY : examples/CMakeFiles/gears.dir/gears.c.obj.provides

examples/CMakeFiles/gears.dir/gears.c.obj.provides.build: examples/CMakeFiles/gears.dir/gears.c.obj


examples/CMakeFiles/gears.dir/glfw.rc.obj: examples/CMakeFiles/gears.dir/flags.make
examples/CMakeFiles/gears.dir/glfw.rc.obj: ../examples/glfw.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object examples/CMakeFiles/gears.dir/glfw.rc.obj"
	cd /d D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\windres.exe -O coff $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\examples\glfw.rc CMakeFiles\gears.dir\glfw.rc.obj

examples/CMakeFiles/gears.dir/glfw.rc.obj.requires:

.PHONY : examples/CMakeFiles/gears.dir/glfw.rc.obj.requires

examples/CMakeFiles/gears.dir/glfw.rc.obj.provides: examples/CMakeFiles/gears.dir/glfw.rc.obj.requires
	$(MAKE) -f examples\CMakeFiles\gears.dir\build.make examples/CMakeFiles/gears.dir/glfw.rc.obj.provides.build
.PHONY : examples/CMakeFiles/gears.dir/glfw.rc.obj.provides

examples/CMakeFiles/gears.dir/glfw.rc.obj.provides.build: examples/CMakeFiles/gears.dir/glfw.rc.obj


examples/CMakeFiles/gears.dir/__/deps/glad.c.obj: examples/CMakeFiles/gears.dir/flags.make
examples/CMakeFiles/gears.dir/__/deps/glad.c.obj: examples/CMakeFiles/gears.dir/includes_C.rsp
examples/CMakeFiles/gears.dir/__/deps/glad.c.obj: ../deps/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object examples/CMakeFiles/gears.dir/__/deps/glad.c.obj"
	cd /d D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\gears.dir\__\deps\glad.c.obj   -c D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\deps\glad.c

examples/CMakeFiles/gears.dir/__/deps/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gears.dir/__/deps/glad.c.i"
	cd /d D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\deps\glad.c > CMakeFiles\gears.dir\__\deps\glad.c.i

examples/CMakeFiles/gears.dir/__/deps/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gears.dir/__/deps/glad.c.s"
	cd /d D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples && C:\PROGRA~2\MINGW-~1\I686-7~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\deps\glad.c -o CMakeFiles\gears.dir\__\deps\glad.c.s

examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.requires:

.PHONY : examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.requires

examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.provides: examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.requires
	$(MAKE) -f examples\CMakeFiles\gears.dir\build.make examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.provides.build
.PHONY : examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.provides

examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.provides.build: examples/CMakeFiles/gears.dir/__/deps/glad.c.obj


# Object files for target gears
gears_OBJECTS = \
"CMakeFiles/gears.dir/gears.c.obj" \
"CMakeFiles/gears.dir/glfw.rc.obj" \
"CMakeFiles/gears.dir/__/deps/glad.c.obj"

# External object files for target gears
gears_EXTERNAL_OBJECTS =

examples/gears.exe: examples/CMakeFiles/gears.dir/gears.c.obj
examples/gears.exe: examples/CMakeFiles/gears.dir/glfw.rc.obj
examples/gears.exe: examples/CMakeFiles/gears.dir/__/deps/glad.c.obj
examples/gears.exe: examples/CMakeFiles/gears.dir/build.make
examples/gears.exe: src/libglfw3.a
examples/gears.exe: examples/CMakeFiles/gears.dir/linklibs.rsp
examples/gears.exe: examples/CMakeFiles/gears.dir/objects1.rsp
examples/gears.exe: examples/CMakeFiles/gears.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable gears.exe"
	cd /d D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\gears.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/CMakeFiles/gears.dir/build: examples/gears.exe

.PHONY : examples/CMakeFiles/gears.dir/build

examples/CMakeFiles/gears.dir/requires: examples/CMakeFiles/gears.dir/gears.c.obj.requires
examples/CMakeFiles/gears.dir/requires: examples/CMakeFiles/gears.dir/glfw.rc.obj.requires
examples/CMakeFiles/gears.dir/requires: examples/CMakeFiles/gears.dir/__/deps/glad.c.obj.requires

.PHONY : examples/CMakeFiles/gears.dir/requires

examples/CMakeFiles/gears.dir/clean:
	cd /d D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples && $(CMAKE_COMMAND) -P CMakeFiles\gears.dir\cmake_clean.cmake
.PHONY : examples/CMakeFiles/gears.dir/clean

examples/CMakeFiles/gears.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\School\Homework\ECE_4122\HW5\glfw-3.2.1 D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\examples D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples D:\School\Homework\ECE_4122\HW5\glfw-3.2.1\cmake-build-debug\examples\CMakeFiles\gears.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : examples/CMakeFiles/gears.dir/depend

