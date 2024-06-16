#include "Broker.h"
#include "MQTTMessageTypes.cpp"
#include <iostream>
#include <vector>
#include <cstring> 
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <mutex>

#pragma comment(lib, "Ws2_32.lib")

/*
    void Broker::deleteTopic(const std::string& topic) {

}
*/


//Add new topic to the list
void Broker::createTopic(const std::string& topic) {
    std::lock_guard<std::mutex> lock(mtx); //We lock mutex to prevent someone of client enter the data while adding new topic

    //Chech if topic already exists
    if (topics.find(topic) == topics.end()) {
        topics.insert(topic);
        std::cout << "Topic created: " << topic << std::endl;
    }
    else {
        std::cout << "Topic already exists" << std::endl;
    }
}

//To review
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

    std::cout << "Received CONNECT from " << clientId << " with protocol " << protocolName
        << ", version " << (int)protocolLevel << ", responding with CONNACK." << std::endl;
}


//Checking active connection between broker and client
void Broker::handlePing(int clientSocket) {
    std::vector<unsigned char> pingResp = { 0xD0, 0x00 };  // PINGRESP packet
    send(clientSocket, reinterpret_cast<const char*>(pingResp.data()), pingResp.size(), 0);
    std::cout << "Received PINGREQ, sent PINGRESP." << std::endl;
}

//To review
void Broker::handlePublish(const std::vector<unsigned char>& message, int clientSocket) {
    if (message.size() < 4) {
        std::cerr << "Invalid PUBLISH packet size." << std::endl;
        return;
    }

    size_t index = 2; 

    uint16_t topicLength = (message[index] << 8) | message[index + 1];
    index += 2;
    std::string topic(message.begin() + index, message.begin() + index + topicLength);
    index += topicLength;

    std::string payload(message.begin() + index, message.end());

    std::cout << "Received PUBLISH on topic " << topic << " with payload: " << payload << std::endl;


    std::lock_guard<std::mutex> lock(mtx);
    if (topicSubscribers.find(topic) != topicSubscribers.end()) {
        for (int subscriberSocket : topicSubscribers[topic]) {
            if (subscriberSocket != clientSocket) {  
                std::vector<unsigned char> publishMessage;
                publishMessage.push_back(0x30);  

                // Calculate remaining length
                size_t remainingLength = 2 + topicLength + payload.size();

                // Encode remaining length
                do {
                    unsigned char encodedByte = remainingLength % 128;
                    remainingLength /= 128;
                    if (remainingLength > 0) {
                        encodedByte |= 128;
                    }
                    publishMessage.push_back(encodedByte);
                } while (remainingLength > 0);

                // Append Topic Length
                publishMessage.push_back(static_cast<unsigned char>(topicLength >> 8));
                publishMessage.push_back(static_cast<unsigned char>(topicLength & 0xFF));

                // Append Topic
                publishMessage.insert(publishMessage.end(), topic.begin(), topic.end());

                // Append Payload
                publishMessage.insert(publishMessage.end(), payload.begin(), payload.end());

                // Send the message
                send(subscriberSocket, reinterpret_cast<const char*>(publishMessage.data()), publishMessage.size(), 0);
            }
        }
    }

}



//Subscribe client to topic
void Broker::handleSubscribe(const std::vector<unsigned char>& message, int clientSocket) {
    size_t index = 4; // Start from first byte of topic

    // Read topic length
    uint16_t topicLength = (message[index] << 8) | message[index + 1];
    index += 2;

    if (index + topicLength > message.size()) {
        std::cerr << "Error: Topic length exceeds remaining message size." << std::endl;
        return;
    }

    
    std::string topic(message.begin() + index, message.begin() + index + topicLength);
    index += topicLength;

    
    uint8_t qos = message[index];

    std::cout << "Subscriber added to topic: " << topic << " with QoS " << static_cast<int>(qos) << std::endl;

    std::lock_guard<std::mutex> lock(mtx);
    topicSubscribers[topic].push_back(clientSocket);

    std::vector<unsigned char> subAck = { 0x90, 0x03, 0x00, 0x00, qos }; // Basic SUBACK packet
    send(clientSocket, reinterpret_cast<const char*>(subAck.data()), subAck.size(), 0);
}

void Broker::handlePuback(const std::vector<unsigned char>& message, int clientSocket) {
    if (message.size() < 4) {
        std::cerr << "Invalid PUBACK packet size." << std::endl;
        return;
    }
    uint16_t packetId = (message[2] << 8) | message[3];
    std::cout << "Received PUBACK"  << std::endl;
}
//Call function depending on message type from the client
void Broker::dispatchMessage(const std::vector<unsigned char>& message, int clientSocket) {
	unsigned char messageType = message[0];

    switch (messageType) {
        case MQTT_MSG_CONNECT:
            handleConnect(message, clientSocket);
            break;
        case MQTT_MSG_PINGREQ:
            handlePing(clientSocket);
            break;
        case MQTT_MSG_PUBLISH:
            handlePublish(message, clientSocket);
            break;
        case MQTT_MSG_SUBSCRIBE:
            handleSubscribe(message, clientSocket);
            break;
        case MQTT_MSG_PUBACK:
            handlePuback(message, clientSocket);
            break;
        default:
            std::cerr << "Unknown message type" << std::endl;
            break;
    }
}
