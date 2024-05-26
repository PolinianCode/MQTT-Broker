#pragma once

#include <vector>
#include <string>

class Broker
{
public:
	void dispatchMessage(const std::vector<unsigned char>& message, int clietnSocket);
private:
    void handleConnect(const std::vector<unsigned char>& message, int clientSocket);
    //void handlePublish(const std::vector<unsigned char>& message);
    //void handleSubscribe(const std::vector<unsigned char>& message);
    //void handlePing(const std::vector<unsigned char>& message);
};

