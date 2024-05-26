#pragma once

#include <vector>
#include <string>

class Broker
{
public:
	void dispatchMessage(const std::vector<unsigned char>& message);
private:
    void handleConnect(const std::vector<unsigned char>& message);
    void handlePublish(const std::vector<unsigned char>& message);
    void handleSubscribe(const std::vector<unsigned char>& message);
    void handlePing(const std::vector<unsigned char>& message);
};

