cmake_minimum_required(VERSION 3.10)
project(MQTTBrokerProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR})

# Add all .cpp files to the list of sources
set(SOURCES
    Broker.cpp
    MQTT-Broker.cpp
    MQTTMessageTypes.cpp
    TCPServer.cpp
    main.cpp
)

# Create the executable
add_executable(MQTTBrokerExecutable ${SOURCES})
