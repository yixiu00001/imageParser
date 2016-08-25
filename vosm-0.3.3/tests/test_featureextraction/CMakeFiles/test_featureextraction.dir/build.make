# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yx/fr/project/imageParser/vosm-0.3.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yx/fr/project/imageParser/vosm-0.3.3

# Include any dependencies generated for this target.
include tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/depend.make

# Include the progress variables for this target.
include tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/progress.make

# Include the compile flags for this target's objects.
include tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/flags.make

tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o: tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/flags.make
tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o: tests/test_featureextraction/featureextraction.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/yx/fr/project/imageParser/vosm-0.3.3/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o"
	cd /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test_featureextraction.dir/featureextraction.o -c /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction/featureextraction.cpp

tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_featureextraction.dir/featureextraction.i"
	cd /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction/featureextraction.cpp > CMakeFiles/test_featureextraction.dir/featureextraction.i

tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_featureextraction.dir/featureextraction.s"
	cd /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction/featureextraction.cpp -o CMakeFiles/test_featureextraction.dir/featureextraction.s

tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o.requires:
.PHONY : tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o.requires

tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o.provides: tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o.requires
	$(MAKE) -f tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/build.make tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o.provides.build
.PHONY : tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o.provides

tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o.provides.build: tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o

# Object files for target test_featureextraction
test_featureextraction_OBJECTS = \
"CMakeFiles/test_featureextraction.dir/featureextraction.o"

# External object files for target test_featureextraction
test_featureextraction_EXTERNAL_OBJECTS =

bin/test_featureextraction: tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o
bin/test_featureextraction: tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/build.make
bin/test_featureextraction: lib/libfeatureextraction.so.0.3.2
bin/test_featureextraction: lib/libintegraltransform.so.0.3.2
bin/test_featureextraction: tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../bin/test_featureextraction"
	cd /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_featureextraction.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/build: bin/test_featureextraction
.PHONY : tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/build

tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/requires: tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/featureextraction.o.requires
.PHONY : tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/requires

tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/clean:
	cd /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction && $(CMAKE_COMMAND) -P CMakeFiles/test_featureextraction.dir/cmake_clean.cmake
.PHONY : tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/clean

tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/depend:
	cd /home/yx/fr/project/imageParser/vosm-0.3.3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yx/fr/project/imageParser/vosm-0.3.3 /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction /home/yx/fr/project/imageParser/vosm-0.3.3 /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction /home/yx/fr/project/imageParser/vosm-0.3.3/tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/test_featureextraction/CMakeFiles/test_featureextraction.dir/depend
