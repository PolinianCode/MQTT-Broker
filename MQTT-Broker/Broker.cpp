#include "Broker.h"
#include "MQTTMessageTypes.cpp"
#include <iostream>
#include <vector>

void Broker::dispatchMessage(const std::vector<unsigned char>& message) {
	unsigned char messageType = message[0];
    switch (messageType) {
        case MQTT_MSG_CONNECT:
            handleConnect(message);
            break;
        case MQTT_MSG_PUBLISH:
            handlePublish(message);
            break;
        case MQTT_MSG_SUBSCRIBE:
            handleSubscribe(message);
            break;
        case MQTT_MSG_PINGREQ:
            handlePing(message);
            break;
        default:
            std::cerr << "Unknown message type" << std::endl;
            break;
    }
}
