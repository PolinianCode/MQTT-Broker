# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build

# Include any dependencies generated for this target.
include CMakeFiles/MQTTBrokerExecutable.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MQTTBrokerExecutable.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MQTTBrokerExecutable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MQTTBrokerExecutable.dir/flags.make

CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/flags.make
CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.o: /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/Broker.cpp
CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.o -MF CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.o.d -o CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.o -c /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/Broker.cpp

CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/Broker.cpp > CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.i

CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/Broker.cpp -o CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.s

CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/flags.make
CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.o: /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/MQTT-Broker.cpp
CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.o -MF CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.o.d -o CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.o -c /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/MQTT-Broker.cpp

CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/MQTT-Broker.cpp > CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.i

CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/MQTT-Broker.cpp -o CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.s

CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/flags.make
CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.o: /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/MQTTMessageTypes.cpp
CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.o -MF CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.o.d -o CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.o -c /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/MQTTMessageTypes.cpp

CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/MQTTMessageTypes.cpp > CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.i

CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/MQTTMessageTypes.cpp -o CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.s

CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/flags.make
CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.o: /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/TCPServer.cpp
CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.o -MF CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.o.d -o CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.o -c /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/TCPServer.cpp

CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/TCPServer.cpp > CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.i

CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/TCPServer.cpp -o CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.s

CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/flags.make
CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.o: /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/main.cpp
CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.o: CMakeFiles/MQTTBrokerExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.o -MF CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.o.d -o CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.o -c /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/main.cpp

CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/main.cpp > CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.i

CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/main.cpp -o CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.s

# Object files for target MQTTBrokerExecutable
MQTTBrokerExecutable_OBJECTS = \
"CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.o" \
"CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.o" \
"CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.o" \
"CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.o" \
"CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.o"

# External object files for target MQTTBrokerExecutable
MQTTBrokerExecutable_EXTERNAL_OBJECTS =

MQTTBrokerExecutable: CMakeFiles/MQTTBrokerExecutable.dir/Broker.cpp.o
MQTTBrokerExecutable: CMakeFiles/MQTTBrokerExecutable.dir/MQTT-Broker.cpp.o
MQTTBrokerExecutable: CMakeFiles/MQTTBrokerExecutable.dir/MQTTMessageTypes.cpp.o
MQTTBrokerExecutable: CMakeFiles/MQTTBrokerExecutable.dir/TCPServer.cpp.o
MQTTBrokerExecutable: CMakeFiles/MQTTBrokerExecutable.dir/main.cpp.o
MQTTBrokerExecutable: CMakeFiles/MQTTBrokerExecutable.dir/build.make
MQTTBrokerExecutable: CMakeFiles/MQTTBrokerExecutable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable MQTTBrokerExecutable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MQTTBrokerExecutable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MQTTBrokerExecutable.dir/build: MQTTBrokerExecutable
.PHONY : CMakeFiles/MQTTBrokerExecutable.dir/build

CMakeFiles/MQTTBrokerExecutable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MQTTBrokerExecutable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MQTTBrokerExecutable.dir/clean

CMakeFiles/MQTTBrokerExecutable.dir/depend:
	cd /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build /home/polinian/Documents/projects/MQTT-Broker/MQTT-Broker/build/CMakeFiles/MQTTBrokerExecutable.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MQTTBrokerExecutable.dir/depend

