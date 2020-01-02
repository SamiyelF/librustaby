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

# Include any dependencies generated for this target.
include CMakeFiles/audio_test_c.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/audio_test_c.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/audio_test_c.dir/flags.make

CMakeFiles/audio_test_c.dir/tests/audio_test.c.o: CMakeFiles/audio_test_c.dir/flags.make
CMakeFiles/audio_test_c.dir/tests/audio_test.c.o: ../tests/audio_test.c
	$(CMAKE_COMMAND) -E cmake_progress_report /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building C object CMakeFiles/audio_test_c.dir/tests/audio_test.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -o CMakeFiles/audio_test_c.dir/tests/audio_test.c.o   -c /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/tests/audio_test.c

CMakeFiles/audio_test_c.dir/tests/audio_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/audio_test_c.dir/tests/audio_test.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -E /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/tests/audio_test.c > CMakeFiles/audio_test_c.dir/tests/audio_test.c.i

CMakeFiles/audio_test_c.dir/tests/audio_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/audio_test_c.dir/tests/audio_test.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_FLAGS) -S /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/tests/audio_test.c -o CMakeFiles/audio_test_c.dir/tests/audio_test.c.s

CMakeFiles/audio_test_c.dir/tests/audio_test.c.o.requires:
.PHONY : CMakeFiles/audio_test_c.dir/tests/audio_test.c.o.requires

CMakeFiles/audio_test_c.dir/tests/audio_test.c.o.provides: CMakeFiles/audio_test_c.dir/tests/audio_test.c.o.requires
	$(MAKE) -f CMakeFiles/audio_test_c.dir/build.make CMakeFiles/audio_test_c.dir/tests/audio_test.c.o.provides.build
.PHONY : CMakeFiles/audio_test_c.dir/tests/audio_test.c.o.provides

CMakeFiles/audio_test_c.dir/tests/audio_test.c.o.provides.build: CMakeFiles/audio_test_c.dir/tests/audio_test.c.o

# Object files for target audio_test_c
audio_test_c_OBJECTS = \
"CMakeFiles/audio_test_c.dir/tests/audio_test.c.o"

# External object files for target audio_test_c
audio_test_c_EXTERNAL_OBJECTS =

audio_test_c: CMakeFiles/audio_test_c.dir/tests/audio_test.c.o
audio_test_c: CMakeFiles/audio_test_c.dir/build.make
audio_test_c: ../lib/libkipr.so
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_videostab.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_ts.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_superres.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_stitching.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_ocl.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_gpu.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_photo.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_legacy.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_contrib.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_video.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_objdetect.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_ml.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_calib3d.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_features2d.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_highgui.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_imgproc.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_flann.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libopencv_core.so.2.4.9
audio_test_c: /usr/lib/arm-linux-gnueabihf/libjpeg.so
audio_test_c: CMakeFiles/audio_test_c.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking C executable audio_test_c"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/audio_test_c.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/audio_test_c.dir/build: audio_test_c
.PHONY : CMakeFiles/audio_test_c.dir/build

CMakeFiles/audio_test_c.dir/requires: CMakeFiles/audio_test_c.dir/tests/audio_test.c.o.requires
.PHONY : CMakeFiles/audio_test_c.dir/requires

CMakeFiles/audio_test_c.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/audio_test_c.dir/cmake_clean.cmake
.PHONY : CMakeFiles/audio_test_c.dir/clean

CMakeFiles/audio_test_c.dir/depend:
	cd /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/got2/libwallaby-v25.2/libwallaby-25.3 /home/pi/got2/libwallaby-v25.2/libwallaby-25.3 /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf /home/pi/got2/libwallaby-v25.2/libwallaby-25.3/obj-arm-linux-gnueabihf/CMakeFiles/audio_test_c.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/audio_test_c.dir/depend

