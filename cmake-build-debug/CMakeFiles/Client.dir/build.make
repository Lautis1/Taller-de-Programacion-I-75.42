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
CMAKE_SOURCE_DIR = "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Client.dir/flags.make

CMakeFiles/Client.dir/src/client/Client.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/client/Client.cpp.o: ../src/client/Client.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Client.dir/src/client/Client.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/client/Client.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Client.cpp"

CMakeFiles/Client.dir/src/client/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/client/Client.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Client.cpp" > CMakeFiles/Client.dir/src/client/Client.cpp.i

CMakeFiles/Client.dir/src/client/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/client/Client.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Client.cpp" -o CMakeFiles/Client.dir/src/client/Client.cpp.s

CMakeFiles/Client.dir/src/client/clientMain.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/client/clientMain.cpp.o: ../src/client/clientMain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Client.dir/src/client/clientMain.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/client/clientMain.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/clientMain.cpp"

CMakeFiles/Client.dir/src/client/clientMain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/client/clientMain.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/clientMain.cpp" > CMakeFiles/Client.dir/src/client/clientMain.cpp.i

CMakeFiles/Client.dir/src/client/clientMain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/client/clientMain.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/clientMain.cpp" -o CMakeFiles/Client.dir/src/client/clientMain.cpp.s

CMakeFiles/Client.dir/src/client/Input.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/client/Input.cpp.o: ../src/client/Input.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Client.dir/src/client/Input.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/client/Input.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Input.cpp"

CMakeFiles/Client.dir/src/client/Input.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/client/Input.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Input.cpp" > CMakeFiles/Client.dir/src/client/Input.cpp.i

CMakeFiles/Client.dir/src/client/Input.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/client/Input.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Input.cpp" -o CMakeFiles/Client.dir/src/client/Input.cpp.s

CMakeFiles/Client.dir/src/client/Login.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/client/Login.cpp.o: ../src/client/Login.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Client.dir/src/client/Login.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/client/Login.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Login.cpp"

CMakeFiles/Client.dir/src/client/Login.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/client/Login.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Login.cpp" > CMakeFiles/Client.dir/src/client/Login.cpp.i

CMakeFiles/Client.dir/src/client/Login.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/client/Login.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Login.cpp" -o CMakeFiles/Client.dir/src/client/Login.cpp.s

CMakeFiles/Client.dir/src/client/Monitor.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/client/Monitor.cpp.o: ../src/client/Monitor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Client.dir/src/client/Monitor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/client/Monitor.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Monitor.cpp"

CMakeFiles/Client.dir/src/client/Monitor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/client/Monitor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Monitor.cpp" > CMakeFiles/Client.dir/src/client/Monitor.cpp.i

CMakeFiles/Client.dir/src/client/Monitor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/client/Monitor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Monitor.cpp" -o CMakeFiles/Client.dir/src/client/Monitor.cpp.s

CMakeFiles/Client.dir/src/client/Processor.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/client/Processor.cpp.o: ../src/client/Processor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Client.dir/src/client/Processor.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/client/Processor.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Processor.cpp"

CMakeFiles/Client.dir/src/client/Processor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/client/Processor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Processor.cpp" > CMakeFiles/Client.dir/src/client/Processor.cpp.i

CMakeFiles/Client.dir/src/client/Processor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/client/Processor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/Processor.cpp" -o CMakeFiles/Client.dir/src/client/Processor.cpp.s

CMakeFiles/Client.dir/src/client/View.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/client/View.cpp.o: ../src/client/View.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Client.dir/src/client/View.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/client/View.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/View.cpp"

CMakeFiles/Client.dir/src/client/View.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/client/View.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/View.cpp" > CMakeFiles/Client.dir/src/client/View.cpp.i

CMakeFiles/Client.dir/src/client/View.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/client/View.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/View.cpp" -o CMakeFiles/Client.dir/src/client/View.cpp.s

CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.o: ../src/common/protocols/EntityInfo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/protocols/EntityInfo.cpp"

CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/protocols/EntityInfo.cpp" > CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.i

CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/protocols/EntityInfo.cpp" -o CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.s

CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.o: ../src/common/protocols/EntityProtocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/protocols/EntityProtocol.cpp"

CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/protocols/EntityProtocol.cpp" > CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.i

CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/protocols/EntityProtocol.cpp" -o CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.s

CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.o: ../src/common/protocols/InputProtocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/protocols/InputProtocol.cpp"

CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/protocols/InputProtocol.cpp" > CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.i

CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/protocols/InputProtocol.cpp" -o CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.s

CMakeFiles/Client.dir/src/common/Config.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/common/Config.cpp.o: ../src/common/Config.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Client.dir/src/common/Config.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/common/Config.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Config.cpp"

CMakeFiles/Client.dir/src/common/Config.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/common/Config.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Config.cpp" > CMakeFiles/Client.dir/src/common/Config.cpp.i

CMakeFiles/Client.dir/src/common/Config.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/common/Config.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Config.cpp" -o CMakeFiles/Client.dir/src/common/Config.cpp.s

CMakeFiles/Client.dir/src/common/Entity.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/common/Entity.cpp.o: ../src/common/Entity.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Client.dir/src/common/Entity.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/common/Entity.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Entity.cpp"

CMakeFiles/Client.dir/src/common/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/common/Entity.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Entity.cpp" > CMakeFiles/Client.dir/src/common/Entity.cpp.i

CMakeFiles/Client.dir/src/common/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/common/Entity.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Entity.cpp" -o CMakeFiles/Client.dir/src/common/Entity.cpp.s

CMakeFiles/Client.dir/src/common/Logger.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/common/Logger.cpp.o: ../src/common/Logger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Client.dir/src/common/Logger.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/common/Logger.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Logger.cpp"

CMakeFiles/Client.dir/src/common/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/common/Logger.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Logger.cpp" > CMakeFiles/Client.dir/src/common/Logger.cpp.i

CMakeFiles/Client.dir/src/common/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/common/Logger.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Logger.cpp" -o CMakeFiles/Client.dir/src/common/Logger.cpp.s

CMakeFiles/Client.dir/src/common/Socket.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/common/Socket.cpp.o: ../src/common/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Client.dir/src/common/Socket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/common/Socket.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Socket.cpp"

CMakeFiles/Client.dir/src/common/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/common/Socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Socket.cpp" > CMakeFiles/Client.dir/src/common/Socket.cpp.i

CMakeFiles/Client.dir/src/common/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/common/Socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Socket.cpp" -o CMakeFiles/Client.dir/src/common/Socket.cpp.s

CMakeFiles/Client.dir/src/common/Thread.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/common/Thread.cpp.o: ../src/common/Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Client.dir/src/common/Thread.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/common/Thread.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Thread.cpp"

CMakeFiles/Client.dir/src/common/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/common/Thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Thread.cpp" > CMakeFiles/Client.dir/src/common/Thread.cpp.i

CMakeFiles/Client.dir/src/common/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/common/Thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/common/Thread.cpp" -o CMakeFiles/Client.dir/src/common/Thread.cpp.s

CMakeFiles/Client.dir/src/client/SDLManager.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/client/SDLManager.cpp.o: ../src/client/SDLManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Client.dir/src/client/SDLManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/client/SDLManager.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/SDLManager.cpp"

CMakeFiles/Client.dir/src/client/SDLManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/client/SDLManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/SDLManager.cpp" > CMakeFiles/Client.dir/src/client/SDLManager.cpp.i

CMakeFiles/Client.dir/src/client/SDLManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/client/SDLManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/SDLManager.cpp" -o CMakeFiles/Client.dir/src/client/SDLManager.cpp.s

CMakeFiles/Client.dir/src/client/SoundManager.cpp.o: CMakeFiles/Client.dir/flags.make
CMakeFiles/Client.dir/src/client/SoundManager.cpp.o: ../src/client/SoundManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Client.dir/src/client/SoundManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Client.dir/src/client/SoundManager.cpp.o -c "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/SoundManager.cpp"

CMakeFiles/Client.dir/src/client/SoundManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Client.dir/src/client/SoundManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/SoundManager.cpp" > CMakeFiles/Client.dir/src/client/SoundManager.cpp.i

CMakeFiles/Client.dir/src/client/SoundManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Client.dir/src/client/SoundManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/src/client/SoundManager.cpp" -o CMakeFiles/Client.dir/src/client/SoundManager.cpp.s

# Object files for target Client
Client_OBJECTS = \
"CMakeFiles/Client.dir/src/client/Client.cpp.o" \
"CMakeFiles/Client.dir/src/client/clientMain.cpp.o" \
"CMakeFiles/Client.dir/src/client/Input.cpp.o" \
"CMakeFiles/Client.dir/src/client/Login.cpp.o" \
"CMakeFiles/Client.dir/src/client/Monitor.cpp.o" \
"CMakeFiles/Client.dir/src/client/Processor.cpp.o" \
"CMakeFiles/Client.dir/src/client/View.cpp.o" \
"CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.o" \
"CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.o" \
"CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.o" \
"CMakeFiles/Client.dir/src/common/Config.cpp.o" \
"CMakeFiles/Client.dir/src/common/Entity.cpp.o" \
"CMakeFiles/Client.dir/src/common/Logger.cpp.o" \
"CMakeFiles/Client.dir/src/common/Socket.cpp.o" \
"CMakeFiles/Client.dir/src/common/Thread.cpp.o" \
"CMakeFiles/Client.dir/src/client/SDLManager.cpp.o" \
"CMakeFiles/Client.dir/src/client/SoundManager.cpp.o"

# External object files for target Client
Client_EXTERNAL_OBJECTS =

Client: CMakeFiles/Client.dir/src/client/Client.cpp.o
Client: CMakeFiles/Client.dir/src/client/clientMain.cpp.o
Client: CMakeFiles/Client.dir/src/client/Input.cpp.o
Client: CMakeFiles/Client.dir/src/client/Login.cpp.o
Client: CMakeFiles/Client.dir/src/client/Monitor.cpp.o
Client: CMakeFiles/Client.dir/src/client/Processor.cpp.o
Client: CMakeFiles/Client.dir/src/client/View.cpp.o
Client: CMakeFiles/Client.dir/src/common/protocols/EntityInfo.cpp.o
Client: CMakeFiles/Client.dir/src/common/protocols/EntityProtocol.cpp.o
Client: CMakeFiles/Client.dir/src/common/protocols/InputProtocol.cpp.o
Client: CMakeFiles/Client.dir/src/common/Config.cpp.o
Client: CMakeFiles/Client.dir/src/common/Entity.cpp.o
Client: CMakeFiles/Client.dir/src/common/Logger.cpp.o
Client: CMakeFiles/Client.dir/src/common/Socket.cpp.o
Client: CMakeFiles/Client.dir/src/common/Thread.cpp.o
Client: CMakeFiles/Client.dir/src/client/SDLManager.cpp.o
Client: CMakeFiles/Client.dir/src/client/SoundManager.cpp.o
Client: CMakeFiles/Client.dir/build.make
Client: CMakeFiles/Client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable Client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Client.dir/build: Client

.PHONY : CMakeFiles/Client.dir/build

CMakeFiles/Client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Client.dir/clean

CMakeFiles/Client.dir/depend:
	cd "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa" "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa" "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug" "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug" "/home/lauti/Documentos/Taller 1 azcurra/Taller-Prog-I-2021-1C-Chipa/cmake-build-debug/CMakeFiles/Client.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Client.dir/depend

