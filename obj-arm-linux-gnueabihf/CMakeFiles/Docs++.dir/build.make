# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.0

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/got2/libwallaby-v25.2/libwallaby-25.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf

# Utility rule file for Docs++.

# Include the progress variables for this target.
include CMakeFiles/Docs++.dir/progress.make

CMakeFiles/Docs++:
	cd /home/pi/got2/libwallaby-v25.2/libwallaby-25.3 && /usr/bin/doxygen /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/doxygen/Doxyfile++

Docs++: CMakeFiles/Docs++
Docs++: CMakeFiles/Docs++.dir/build.make
.PHONY : Docs++

# Rule to build all files generated by this target.
CMakeFiles/Docs++.dir/build: Docs++
.PHONY : CMakeFiles/Docs++.dir/build

CMakeFiles/Docs++.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Docs++.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Docs++.dir/clean

CMakeFiles/Docs++.dir/depend:
	cd /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/got2/libwallaby-v25.2/libwallaby-25.3 /home/pi/got2/libwallaby-v25.2/libwallaby-25.3 /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf/CMakeFiles/Docs++.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Docs++.dir/depend

