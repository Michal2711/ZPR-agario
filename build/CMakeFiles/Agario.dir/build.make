# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/michalkopec/SEM5/ZPR_Projekt/projekt

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/michalkopec/SEM5/ZPR_Projekt/projekt/build

# Include any dependencies generated for this target.
include CMakeFiles/Agario.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Agario.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Agario.dir/flags.make

CMakeFiles/Agario.dir/src/main.cpp.o: CMakeFiles/Agario.dir/flags.make
CMakeFiles/Agario.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michalkopec/SEM5/ZPR_Projekt/projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Agario.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Agario.dir/src/main.cpp.o -c /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/main.cpp

CMakeFiles/Agario.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Agario.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/main.cpp > CMakeFiles/Agario.dir/src/main.cpp.i

CMakeFiles/Agario.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Agario.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/main.cpp -o CMakeFiles/Agario.dir/src/main.cpp.s

CMakeFiles/Agario.dir/src/Ball.cpp.o: CMakeFiles/Agario.dir/flags.make
CMakeFiles/Agario.dir/src/Ball.cpp.o: ../src/Ball.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michalkopec/SEM5/ZPR_Projekt/projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Agario.dir/src/Ball.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Agario.dir/src/Ball.cpp.o -c /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Ball.cpp

CMakeFiles/Agario.dir/src/Ball.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Agario.dir/src/Ball.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Ball.cpp > CMakeFiles/Agario.dir/src/Ball.cpp.i

CMakeFiles/Agario.dir/src/Ball.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Agario.dir/src/Ball.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Ball.cpp -o CMakeFiles/Agario.dir/src/Ball.cpp.s

CMakeFiles/Agario.dir/src/Game.cpp.o: CMakeFiles/Agario.dir/flags.make
CMakeFiles/Agario.dir/src/Game.cpp.o: ../src/Game.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michalkopec/SEM5/ZPR_Projekt/projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Agario.dir/src/Game.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Agario.dir/src/Game.cpp.o -c /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Game.cpp

CMakeFiles/Agario.dir/src/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Agario.dir/src/Game.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Game.cpp > CMakeFiles/Agario.dir/src/Game.cpp.i

CMakeFiles/Agario.dir/src/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Agario.dir/src/Game.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Game.cpp -o CMakeFiles/Agario.dir/src/Game.cpp.s

CMakeFiles/Agario.dir/src/Player.cpp.o: CMakeFiles/Agario.dir/flags.make
CMakeFiles/Agario.dir/src/Player.cpp.o: ../src/Player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michalkopec/SEM5/ZPR_Projekt/projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Agario.dir/src/Player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Agario.dir/src/Player.cpp.o -c /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Player.cpp

CMakeFiles/Agario.dir/src/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Agario.dir/src/Player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Player.cpp > CMakeFiles/Agario.dir/src/Player.cpp.i

CMakeFiles/Agario.dir/src/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Agario.dir/src/Player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Player.cpp -o CMakeFiles/Agario.dir/src/Player.cpp.s

CMakeFiles/Agario.dir/src/Board.cpp.o: CMakeFiles/Agario.dir/flags.make
CMakeFiles/Agario.dir/src/Board.cpp.o: ../src/Board.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/michalkopec/SEM5/ZPR_Projekt/projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Agario.dir/src/Board.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Agario.dir/src/Board.cpp.o -c /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Board.cpp

CMakeFiles/Agario.dir/src/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Agario.dir/src/Board.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Board.cpp > CMakeFiles/Agario.dir/src/Board.cpp.i

CMakeFiles/Agario.dir/src/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Agario.dir/src/Board.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/michalkopec/SEM5/ZPR_Projekt/projekt/src/Board.cpp -o CMakeFiles/Agario.dir/src/Board.cpp.s

# Object files for target Agario
Agario_OBJECTS = \
"CMakeFiles/Agario.dir/src/main.cpp.o" \
"CMakeFiles/Agario.dir/src/Ball.cpp.o" \
"CMakeFiles/Agario.dir/src/Game.cpp.o" \
"CMakeFiles/Agario.dir/src/Player.cpp.o" \
"CMakeFiles/Agario.dir/src/Board.cpp.o"

# External object files for target Agario
Agario_EXTERNAL_OBJECTS =

Agario: CMakeFiles/Agario.dir/src/main.cpp.o
Agario: CMakeFiles/Agario.dir/src/Ball.cpp.o
Agario: CMakeFiles/Agario.dir/src/Game.cpp.o
Agario: CMakeFiles/Agario.dir/src/Player.cpp.o
Agario: CMakeFiles/Agario.dir/src/Board.cpp.o
Agario: CMakeFiles/Agario.dir/build.make
Agario: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
Agario: /usr/lib/x86_64-linux-gnu/libsfml-audio.so.2.5.1
Agario: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
Agario: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
Agario: /usr/lib/x86_64-linux-gnu/libboost_unit_test_framework.so.1.71.0
Agario: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
Agario: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
Agario: CMakeFiles/Agario.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/michalkopec/SEM5/ZPR_Projekt/projekt/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Agario"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Agario.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Agario.dir/build: Agario

.PHONY : CMakeFiles/Agario.dir/build

CMakeFiles/Agario.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Agario.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Agario.dir/clean

CMakeFiles/Agario.dir/depend:
	cd /home/michalkopec/SEM5/ZPR_Projekt/projekt/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/michalkopec/SEM5/ZPR_Projekt/projekt /home/michalkopec/SEM5/ZPR_Projekt/projekt /home/michalkopec/SEM5/ZPR_Projekt/projekt/build /home/michalkopec/SEM5/ZPR_Projekt/projekt/build /home/michalkopec/SEM5/ZPR_Projekt/projekt/build/CMakeFiles/Agario.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Agario.dir/depend

