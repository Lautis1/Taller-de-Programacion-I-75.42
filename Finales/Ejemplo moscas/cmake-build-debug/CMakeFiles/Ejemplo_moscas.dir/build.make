# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /home/lauti/Descargas/clion-2021.1.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lauti/Descargas/clion-2021.1.2/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Ejemplo_moscas.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Ejemplo_moscas.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Ejemplo_moscas.dir/flags.make

CMakeFiles/Ejemplo_moscas.dir/main.cpp.o: CMakeFiles/Ejemplo_moscas.dir/flags.make
CMakeFiles/Ejemplo_moscas.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Ejemplo_moscas.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Ejemplo_moscas.dir/main.cpp.o -c "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/main.cpp"

CMakeFiles/Ejemplo_moscas.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Ejemplo_moscas.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/main.cpp" > CMakeFiles/Ejemplo_moscas.dir/main.cpp.i

CMakeFiles/Ejemplo_moscas.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Ejemplo_moscas.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/main.cpp" -o CMakeFiles/Ejemplo_moscas.dir/main.cpp.s

# Object files for target Ejemplo_moscas
Ejemplo_moscas_OBJECTS = \
"CMakeFiles/Ejemplo_moscas.dir/main.cpp.o"

# External object files for target Ejemplo_moscas
Ejemplo_moscas_EXTERNAL_OBJECTS =

Ejemplo_moscas: CMakeFiles/Ejemplo_moscas.dir/main.cpp.o
Ejemplo_moscas: CMakeFiles/Ejemplo_moscas.dir/build.make
Ejemplo_moscas: CMakeFiles/Ejemplo_moscas.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Ejemplo_moscas"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Ejemplo_moscas.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Ejemplo_moscas.dir/build: Ejemplo_moscas

.PHONY : CMakeFiles/Ejemplo_moscas.dir/build

CMakeFiles/Ejemplo_moscas.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Ejemplo_moscas.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Ejemplo_moscas.dir/clean

CMakeFiles/Ejemplo_moscas.dir/depend:
	cd "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas" "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas" "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/cmake-build-debug" "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/cmake-build-debug" "/home/lauti/Documentos/Practica Final taller azcurra/Ejemplo moscas/cmake-build-debug/CMakeFiles/Ejemplo_moscas.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Ejemplo_moscas.dir/depend

