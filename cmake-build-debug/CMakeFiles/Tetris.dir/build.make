# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/MrIggyman1234/ClionProjects/Tetris

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Tetris.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tetris.dir/flags.make

CMakeFiles/Tetris.dir/main.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tetris.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/main.cpp.o -c /Users/MrIggyman1234/ClionProjects/Tetris/main.cpp

CMakeFiles/Tetris.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/MrIggyman1234/ClionProjects/Tetris/main.cpp > CMakeFiles/Tetris.dir/main.cpp.i

CMakeFiles/Tetris.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/MrIggyman1234/ClionProjects/Tetris/main.cpp -o CMakeFiles/Tetris.dir/main.cpp.s

CMakeFiles/Tetris.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Tetris.dir/main.cpp.o.requires

CMakeFiles/Tetris.dir/main.cpp.o.provides: CMakeFiles/Tetris.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/main.cpp.o.provides

CMakeFiles/Tetris.dir/main.cpp.o.provides.build: CMakeFiles/Tetris.dir/main.cpp.o


CMakeFiles/Tetris.dir/Game.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/Game.cpp.o: ../Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Tetris.dir/Game.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/Game.cpp.o -c /Users/MrIggyman1234/ClionProjects/Tetris/Game.cpp

CMakeFiles/Tetris.dir/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/Game.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/MrIggyman1234/ClionProjects/Tetris/Game.cpp > CMakeFiles/Tetris.dir/Game.cpp.i

CMakeFiles/Tetris.dir/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/Game.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/MrIggyman1234/ClionProjects/Tetris/Game.cpp -o CMakeFiles/Tetris.dir/Game.cpp.s

CMakeFiles/Tetris.dir/Game.cpp.o.requires:

.PHONY : CMakeFiles/Tetris.dir/Game.cpp.o.requires

CMakeFiles/Tetris.dir/Game.cpp.o.provides: CMakeFiles/Tetris.dir/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/Game.cpp.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/Game.cpp.o.provides

CMakeFiles/Tetris.dir/Game.cpp.o.provides.build: CMakeFiles/Tetris.dir/Game.cpp.o


CMakeFiles/Tetris.dir/Block.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/Block.cpp.o: ../Block.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Tetris.dir/Block.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/Block.cpp.o -c /Users/MrIggyman1234/ClionProjects/Tetris/Block.cpp

CMakeFiles/Tetris.dir/Block.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/Block.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/MrIggyman1234/ClionProjects/Tetris/Block.cpp > CMakeFiles/Tetris.dir/Block.cpp.i

CMakeFiles/Tetris.dir/Block.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/Block.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/MrIggyman1234/ClionProjects/Tetris/Block.cpp -o CMakeFiles/Tetris.dir/Block.cpp.s

CMakeFiles/Tetris.dir/Block.cpp.o.requires:

.PHONY : CMakeFiles/Tetris.dir/Block.cpp.o.requires

CMakeFiles/Tetris.dir/Block.cpp.o.provides: CMakeFiles/Tetris.dir/Block.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/Block.cpp.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/Block.cpp.o.provides

CMakeFiles/Tetris.dir/Block.cpp.o.provides.build: CMakeFiles/Tetris.dir/Block.cpp.o


CMakeFiles/Tetris.dir/Structure.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/Structure.cpp.o: ../Structure.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Tetris.dir/Structure.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/Structure.cpp.o -c /Users/MrIggyman1234/ClionProjects/Tetris/Structure.cpp

CMakeFiles/Tetris.dir/Structure.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/Structure.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/MrIggyman1234/ClionProjects/Tetris/Structure.cpp > CMakeFiles/Tetris.dir/Structure.cpp.i

CMakeFiles/Tetris.dir/Structure.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/Structure.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/MrIggyman1234/ClionProjects/Tetris/Structure.cpp -o CMakeFiles/Tetris.dir/Structure.cpp.s

CMakeFiles/Tetris.dir/Structure.cpp.o.requires:

.PHONY : CMakeFiles/Tetris.dir/Structure.cpp.o.requires

CMakeFiles/Tetris.dir/Structure.cpp.o.provides: CMakeFiles/Tetris.dir/Structure.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/Structure.cpp.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/Structure.cpp.o.provides

CMakeFiles/Tetris.dir/Structure.cpp.o.provides.build: CMakeFiles/Tetris.dir/Structure.cpp.o


CMakeFiles/Tetris.dir/cCoord.cpp.o: CMakeFiles/Tetris.dir/flags.make
CMakeFiles/Tetris.dir/cCoord.cpp.o: ../cCoord.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Tetris.dir/cCoord.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tetris.dir/cCoord.cpp.o -c /Users/MrIggyman1234/ClionProjects/Tetris/cCoord.cpp

CMakeFiles/Tetris.dir/cCoord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tetris.dir/cCoord.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/MrIggyman1234/ClionProjects/Tetris/cCoord.cpp > CMakeFiles/Tetris.dir/cCoord.cpp.i

CMakeFiles/Tetris.dir/cCoord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tetris.dir/cCoord.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/MrIggyman1234/ClionProjects/Tetris/cCoord.cpp -o CMakeFiles/Tetris.dir/cCoord.cpp.s

CMakeFiles/Tetris.dir/cCoord.cpp.o.requires:

.PHONY : CMakeFiles/Tetris.dir/cCoord.cpp.o.requires

CMakeFiles/Tetris.dir/cCoord.cpp.o.provides: CMakeFiles/Tetris.dir/cCoord.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tetris.dir/build.make CMakeFiles/Tetris.dir/cCoord.cpp.o.provides.build
.PHONY : CMakeFiles/Tetris.dir/cCoord.cpp.o.provides

CMakeFiles/Tetris.dir/cCoord.cpp.o.provides.build: CMakeFiles/Tetris.dir/cCoord.cpp.o


# Object files for target Tetris
Tetris_OBJECTS = \
"CMakeFiles/Tetris.dir/main.cpp.o" \
"CMakeFiles/Tetris.dir/Game.cpp.o" \
"CMakeFiles/Tetris.dir/Block.cpp.o" \
"CMakeFiles/Tetris.dir/Structure.cpp.o" \
"CMakeFiles/Tetris.dir/cCoord.cpp.o"

# External object files for target Tetris
Tetris_EXTERNAL_OBJECTS =

Tetris: CMakeFiles/Tetris.dir/main.cpp.o
Tetris: CMakeFiles/Tetris.dir/Game.cpp.o
Tetris: CMakeFiles/Tetris.dir/Block.cpp.o
Tetris: CMakeFiles/Tetris.dir/Structure.cpp.o
Tetris: CMakeFiles/Tetris.dir/cCoord.cpp.o
Tetris: CMakeFiles/Tetris.dir/build.make
Tetris: CMakeFiles/Tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Tetris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tetris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tetris.dir/build: Tetris

.PHONY : CMakeFiles/Tetris.dir/build

CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/main.cpp.o.requires
CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/Game.cpp.o.requires
CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/Block.cpp.o.requires
CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/Structure.cpp.o.requires
CMakeFiles/Tetris.dir/requires: CMakeFiles/Tetris.dir/cCoord.cpp.o.requires

.PHONY : CMakeFiles/Tetris.dir/requires

CMakeFiles/Tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tetris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tetris.dir/clean

CMakeFiles/Tetris.dir/depend:
	cd /Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/MrIggyman1234/ClionProjects/Tetris /Users/MrIggyman1234/ClionProjects/Tetris /Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug /Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug /Users/MrIggyman1234/ClionProjects/Tetris/cmake-build-debug/CMakeFiles/Tetris.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Tetris.dir/depend
