# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zwh/myStudies/C++/git/template

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zwh/myStudies/C++/git/template/build

# Include any dependencies generated for this target.
include Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/compiler_depend.make

# Include the progress variables for this target.
include Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/progress.make

# Include the compile flags for this target's objects.
include Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/flags.make

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/string_zwh.cpp.o: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/flags.make
Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/string_zwh.cpp.o: ../Libraries/ZWH_App/string_zwh.cpp
Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/string_zwh.cpp.o: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zwh/myStudies/C++/git/template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/string_zwh.cpp.o"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/string_zwh.cpp.o -MF CMakeFiles/ZWH_App.dir/string_zwh.cpp.o.d -o CMakeFiles/ZWH_App.dir/string_zwh.cpp.o -c /home/zwh/myStudies/C++/git/template/Libraries/ZWH_App/string_zwh.cpp

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/string_zwh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZWH_App.dir/string_zwh.cpp.i"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwh/myStudies/C++/git/template/Libraries/ZWH_App/string_zwh.cpp > CMakeFiles/ZWH_App.dir/string_zwh.cpp.i

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/string_zwh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZWH_App.dir/string_zwh.cpp.s"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwh/myStudies/C++/git/template/Libraries/ZWH_App/string_zwh.cpp -o CMakeFiles/ZWH_App.dir/string_zwh.cpp.s

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/collection_zwh.cpp.o: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/flags.make
Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/collection_zwh.cpp.o: ../Libraries/ZWH_App/collection_zwh.cpp
Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/collection_zwh.cpp.o: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zwh/myStudies/C++/git/template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/collection_zwh.cpp.o"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/collection_zwh.cpp.o -MF CMakeFiles/ZWH_App.dir/collection_zwh.cpp.o.d -o CMakeFiles/ZWH_App.dir/collection_zwh.cpp.o -c /home/zwh/myStudies/C++/git/template/Libraries/ZWH_App/collection_zwh.cpp

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/collection_zwh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZWH_App.dir/collection_zwh.cpp.i"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zwh/myStudies/C++/git/template/Libraries/ZWH_App/collection_zwh.cpp > CMakeFiles/ZWH_App.dir/collection_zwh.cpp.i

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/collection_zwh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZWH_App.dir/collection_zwh.cpp.s"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zwh/myStudies/C++/git/template/Libraries/ZWH_App/collection_zwh.cpp -o CMakeFiles/ZWH_App.dir/collection_zwh.cpp.s

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.o: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/flags.make
Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.o: ../Libraries/ZWH_App/Stacks&Queues.cpp
Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.o: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zwh/myStudies/C++/git/template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.o"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT "Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.o" -MF "CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.o.d" -o "CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.o" -c "/home/zwh/myStudies/C++/git/template/Libraries/ZWH_App/Stacks&Queues.cpp"

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.i"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/zwh/myStudies/C++/git/template/Libraries/ZWH_App/Stacks&Queues.cpp" > "CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.i"

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.s"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && /usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/zwh/myStudies/C++/git/template/Libraries/ZWH_App/Stacks&Queues.cpp" -o "CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.s"

# Object files for target ZWH_App
ZWH_App_OBJECTS = \
"CMakeFiles/ZWH_App.dir/string_zwh.cpp.o" \
"CMakeFiles/ZWH_App.dir/collection_zwh.cpp.o" \
"CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.o"

# External object files for target ZWH_App
ZWH_App_EXTERNAL_OBJECTS =

Libraries/ZWH_App/libZWH_App.a: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/string_zwh.cpp.o
Libraries/ZWH_App/libZWH_App.a: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/collection_zwh.cpp.o
Libraries/ZWH_App/libZWH_App.a: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/Stacks&Queues.cpp.o
Libraries/ZWH_App/libZWH_App.a: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/build.make
Libraries/ZWH_App/libZWH_App.a: Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zwh/myStudies/C++/git/template/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libZWH_App.a"
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && $(CMAKE_COMMAND) -P CMakeFiles/ZWH_App.dir/cmake_clean_target.cmake
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ZWH_App.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/build: Libraries/ZWH_App/libZWH_App.a
.PHONY : Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/build

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/clean:
	cd /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App && $(CMAKE_COMMAND) -P CMakeFiles/ZWH_App.dir/cmake_clean.cmake
.PHONY : Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/clean

Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/depend:
	cd /home/zwh/myStudies/C++/git/template/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zwh/myStudies/C++/git/template /home/zwh/myStudies/C++/git/template/Libraries/ZWH_App /home/zwh/myStudies/C++/git/template/build /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App /home/zwh/myStudies/C++/git/template/build/Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Libraries/ZWH_App/CMakeFiles/ZWH_App.dir/depend

