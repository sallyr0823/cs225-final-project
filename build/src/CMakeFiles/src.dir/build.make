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
CMAKE_SOURCE_DIR = /workspaces/final_proj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/final_proj/build

# Include any dependencies generated for this target.
include src/CMakeFiles/src.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/src.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/src.dir/flags.make

src/CMakeFiles/src.dir/BFS.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/BFS.cpp.o: ../src/BFS.cpp
src/CMakeFiles/src.dir/BFS.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/final_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/src.dir/BFS.cpp.o"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/BFS.cpp.o -MF CMakeFiles/src.dir/BFS.cpp.o.d -o CMakeFiles/src.dir/BFS.cpp.o -c /workspaces/final_proj/src/BFS.cpp

src/CMakeFiles/src.dir/BFS.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/BFS.cpp.i"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/final_proj/src/BFS.cpp > CMakeFiles/src.dir/BFS.cpp.i

src/CMakeFiles/src.dir/BFS.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/BFS.cpp.s"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/final_proj/src/BFS.cpp -o CMakeFiles/src.dir/BFS.cpp.s

src/CMakeFiles/src.dir/airport.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/airport.cpp.o: ../src/airport.cpp
src/CMakeFiles/src.dir/airport.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/final_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/src.dir/airport.cpp.o"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/airport.cpp.o -MF CMakeFiles/src.dir/airport.cpp.o.d -o CMakeFiles/src.dir/airport.cpp.o -c /workspaces/final_proj/src/airport.cpp

src/CMakeFiles/src.dir/airport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/airport.cpp.i"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/final_proj/src/airport.cpp > CMakeFiles/src.dir/airport.cpp.i

src/CMakeFiles/src.dir/airport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/airport.cpp.s"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/final_proj/src/airport.cpp -o CMakeFiles/src.dir/airport.cpp.s

src/CMakeFiles/src.dir/airport_graph.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/airport_graph.cpp.o: ../src/airport_graph.cpp
src/CMakeFiles/src.dir/airport_graph.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/final_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/src.dir/airport_graph.cpp.o"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/airport_graph.cpp.o -MF CMakeFiles/src.dir/airport_graph.cpp.o.d -o CMakeFiles/src.dir/airport_graph.cpp.o -c /workspaces/final_proj/src/airport_graph.cpp

src/CMakeFiles/src.dir/airport_graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/airport_graph.cpp.i"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/final_proj/src/airport_graph.cpp > CMakeFiles/src.dir/airport_graph.cpp.i

src/CMakeFiles/src.dir/airport_graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/airport_graph.cpp.s"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/final_proj/src/airport_graph.cpp -o CMakeFiles/src.dir/airport_graph.cpp.s

src/CMakeFiles/src.dir/dijikstra.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/dijikstra.cpp.o: ../src/dijikstra.cpp
src/CMakeFiles/src.dir/dijikstra.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/final_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/src.dir/dijikstra.cpp.o"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/dijikstra.cpp.o -MF CMakeFiles/src.dir/dijikstra.cpp.o.d -o CMakeFiles/src.dir/dijikstra.cpp.o -c /workspaces/final_proj/src/dijikstra.cpp

src/CMakeFiles/src.dir/dijikstra.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/dijikstra.cpp.i"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/final_proj/src/dijikstra.cpp > CMakeFiles/src.dir/dijikstra.cpp.i

src/CMakeFiles/src.dir/dijikstra.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/dijikstra.cpp.s"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/final_proj/src/dijikstra.cpp -o CMakeFiles/src.dir/dijikstra.cpp.s

src/CMakeFiles/src.dir/edge.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/edge.cpp.o: ../src/edge.cpp
src/CMakeFiles/src.dir/edge.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/final_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/src.dir/edge.cpp.o"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/edge.cpp.o -MF CMakeFiles/src.dir/edge.cpp.o.d -o CMakeFiles/src.dir/edge.cpp.o -c /workspaces/final_proj/src/edge.cpp

src/CMakeFiles/src.dir/edge.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/edge.cpp.i"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/final_proj/src/edge.cpp > CMakeFiles/src.dir/edge.cpp.i

src/CMakeFiles/src.dir/edge.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/edge.cpp.s"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/final_proj/src/edge.cpp -o CMakeFiles/src.dir/edge.cpp.s

src/CMakeFiles/src.dir/file_reader.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/file_reader.cpp.o: ../src/file_reader.cpp
src/CMakeFiles/src.dir/file_reader.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/final_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/src.dir/file_reader.cpp.o"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/file_reader.cpp.o -MF CMakeFiles/src.dir/file_reader.cpp.o.d -o CMakeFiles/src.dir/file_reader.cpp.o -c /workspaces/final_proj/src/file_reader.cpp

src/CMakeFiles/src.dir/file_reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/file_reader.cpp.i"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/final_proj/src/file_reader.cpp > CMakeFiles/src.dir/file_reader.cpp.i

src/CMakeFiles/src.dir/file_reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/file_reader.cpp.s"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/final_proj/src/file_reader.cpp -o CMakeFiles/src.dir/file_reader.cpp.s

src/CMakeFiles/src.dir/pagerank.cpp.o: src/CMakeFiles/src.dir/flags.make
src/CMakeFiles/src.dir/pagerank.cpp.o: ../src/pagerank.cpp
src/CMakeFiles/src.dir/pagerank.cpp.o: src/CMakeFiles/src.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/final_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object src/CMakeFiles/src.dir/pagerank.cpp.o"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/src.dir/pagerank.cpp.o -MF CMakeFiles/src.dir/pagerank.cpp.o.d -o CMakeFiles/src.dir/pagerank.cpp.o -c /workspaces/final_proj/src/pagerank.cpp

src/CMakeFiles/src.dir/pagerank.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/pagerank.cpp.i"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/final_proj/src/pagerank.cpp > CMakeFiles/src.dir/pagerank.cpp.i

src/CMakeFiles/src.dir/pagerank.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/pagerank.cpp.s"
	cd /workspaces/final_proj/build/src && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/final_proj/src/pagerank.cpp -o CMakeFiles/src.dir/pagerank.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/BFS.cpp.o" \
"CMakeFiles/src.dir/airport.cpp.o" \
"CMakeFiles/src.dir/airport_graph.cpp.o" \
"CMakeFiles/src.dir/dijikstra.cpp.o" \
"CMakeFiles/src.dir/edge.cpp.o" \
"CMakeFiles/src.dir/file_reader.cpp.o" \
"CMakeFiles/src.dir/pagerank.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src/libsrc.a: src/CMakeFiles/src.dir/BFS.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/airport.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/airport_graph.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/dijikstra.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/edge.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/file_reader.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/pagerank.cpp.o
src/libsrc.a: src/CMakeFiles/src.dir/build.make
src/libsrc.a: src/CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/final_proj/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX static library libsrc.a"
	cd /workspaces/final_proj/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean_target.cmake
	cd /workspaces/final_proj/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/src.dir/build: src/libsrc.a
.PHONY : src/CMakeFiles/src.dir/build

src/CMakeFiles/src.dir/clean:
	cd /workspaces/final_proj/build/src && $(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/src.dir/clean

src/CMakeFiles/src.dir/depend:
	cd /workspaces/final_proj/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/final_proj /workspaces/final_proj/src /workspaces/final_proj/build /workspaces/final_proj/build/src /workspaces/final_proj/build/src/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/src.dir/depend

