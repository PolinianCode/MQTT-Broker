#include "Broker.h"
#include "MQTTMessageTypes.cpp"
#include <iostream>
#include <vector>
#include <cstring> 
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "Ws2_32.lib")


void Broker::handleConnect(const std::vector<unsigned char>& message, int clientSocket) {
    if (message.size() < 10) { 
        std::cerr << "Invalid CONNECT packet size." << std::endl;
        return;
    }

    
    size_t index = 2;

    // Extract Protocol Name
    uint16_t name_length = (message[index] << 8) | message[index + 1];
    index += 2;
    std::string protocolName(message.begin() + index, message.begin() + index + name_length);
    index += name_length;

    // Protocol Level
    unsigned char protocolLevel = message[index++];

    // Connect Flags
    unsigned char connectFlags = message[index++];

    // Keep Alive
    uint16_t keepAlive = (message[index] << 8) | message[index + 1];
    index += 2;


    uint16_t clientIdLength = (message[index] << 8) | message[index + 1];
    index += 2;
    std::string clientId(message.begin() + index, message.begin() + index + clientIdLength);
    index += clientIdLength;

    // Respond with CONNACK
    std::vector<unsigned char> connAck = { 0x20, 0x02, 0x00, 0x00 };
    send(clientSocket, reinterpret_cast<const char*>(connAck.data()), connAck.size(), 0);

    std::cout << "Received CONNECT from " << clientId << ", responding with CONNACK." << std::endl;
}


void Broker::dispatchMessage(const std::vector<unsigned char>& message, int clientSocket) {
	unsigned char messageType = message[0];
    switch (messageType) {
        case MQTT_MSG_CONNECT:
            handleConnect(message, clientSocket);
            break;
        /*case MQTT_MSG_PUBLISH:
            handlePublish(message);
            break;
        case MQTT_MSG_SUBSCRIBE:
            handleSubscribe(message);
            break;
        case MQTT_MSG_PINGREQ:
            handlePing(message);
            break;
        */
        default:
            std::cerr << "Unknown message type" << std::endl;
            break;
    }
}
