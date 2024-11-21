# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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
CMAKE_SOURCE_DIR = /home/linqinyang/Gluttony_Snake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/linqinyang/Gluttony_Snake/build

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/linqinyang/Gluttony_Snake/build/CMakeFiles /home/linqinyang/Gluttony_Snake/build//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/linqinyang/Gluttony_Snake/build/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named snake

# Build rule for target.
snake: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 snake
.PHONY : snake

# fast build rule for target.
snake/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/build
.PHONY : snake/fast

src/a_star.o: src/a_star.cpp.o
.PHONY : src/a_star.o

# target to build an object file
src/a_star.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/a_star.cpp.o
.PHONY : src/a_star.cpp.o

src/a_star.i: src/a_star.cpp.i
.PHONY : src/a_star.i

# target to preprocess a source file
src/a_star.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/a_star.cpp.i
.PHONY : src/a_star.cpp.i

src/a_star.s: src/a_star.cpp.s
.PHONY : src/a_star.s

# target to generate assembly for a file
src/a_star.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/a_star.cpp.s
.PHONY : src/a_star.cpp.s

src/engine.o: src/engine.cpp.o
.PHONY : src/engine.o

# target to build an object file
src/engine.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/engine.cpp.o
.PHONY : src/engine.cpp.o

src/engine.i: src/engine.cpp.i
.PHONY : src/engine.i

# target to preprocess a source file
src/engine.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/engine.cpp.i
.PHONY : src/engine.cpp.i

src/engine.s: src/engine.cpp.s
.PHONY : src/engine.s

# target to generate assembly for a file
src/engine.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/engine.cpp.s
.PHONY : src/engine.cpp.s

src/game.o: src/game.cpp.o
.PHONY : src/game.o

# target to build an object file
src/game.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/game.cpp.o
.PHONY : src/game.cpp.o

src/game.i: src/game.cpp.i
.PHONY : src/game.i

# target to preprocess a source file
src/game.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/game.cpp.i
.PHONY : src/game.cpp.i

src/game.s: src/game.cpp.s
.PHONY : src/game.s

# target to generate assembly for a file
src/game.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/game.cpp.s
.PHONY : src/game.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/node.o: src/node.cpp.o
.PHONY : src/node.o

# target to build an object file
src/node.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/node.cpp.o
.PHONY : src/node.cpp.o

src/node.i: src/node.cpp.i
.PHONY : src/node.i

# target to preprocess a source file
src/node.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/node.cpp.i
.PHONY : src/node.cpp.i

src/node.s: src/node.cpp.s
.PHONY : src/node.s

# target to generate assembly for a file
src/node.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/node.cpp.s
.PHONY : src/node.cpp.s

src/snake.o: src/snake.cpp.o
.PHONY : src/snake.o

# target to build an object file
src/snake.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/snake.cpp.o
.PHONY : src/snake.cpp.o

src/snake.i: src/snake.cpp.i
.PHONY : src/snake.i

# target to preprocess a source file
src/snake.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/snake.cpp.i
.PHONY : src/snake.cpp.i

src/snake.s: src/snake.cpp.s
.PHONY : src/snake.s

# target to generate assembly for a file
src/snake.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/snake.dir/build.make CMakeFiles/snake.dir/src/snake.cpp.s
.PHONY : src/snake.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... snake"
	@echo "... src/a_star.o"
	@echo "... src/a_star.i"
	@echo "... src/a_star.s"
	@echo "... src/engine.o"
	@echo "... src/engine.i"
	@echo "... src/engine.s"
	@echo "... src/game.o"
	@echo "... src/game.i"
	@echo "... src/game.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/node.o"
	@echo "... src/node.i"
	@echo "... src/node.s"
	@echo "... src/snake.o"
	@echo "... src/snake.i"
	@echo "... src/snake.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
