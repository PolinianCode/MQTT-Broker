#pragma once
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <mutex>

class Broker
{
public:
    void handleConnect(const std::vector<unsigned char>& message, int clientSocket);
    void handlePublish(const std::vector<unsigned char>& message, int clientSocket);
    void handleSubscribe(const std::vector<unsigned char>& message, int clientSocket);
    void handlePing(int clientSocket);
	void dispatchMessage(const std::vector<unsigned char>& message, int clietnSocket);

    void createTopic(const std::string& topic);
    void deleteTopic(const std::string& topic);

    std::vector<std::string> listTopics() const;
private:
    std::unordered_map<std::string, std::vector<int>> topicSubscribers;  // Topic to client sockets
    std::unordered_set<std::string> topics;  // Set of all topics
    std::mutex mtx;
};

