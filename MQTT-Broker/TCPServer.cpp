#include "TCPServer.h"
#include "Broker.h"
#include <thread>


#pragma comment(lib, "Ws2_32.lib")

TCPServer::TCPServer() :serverSocket(INVALID_SOCKET) {
	initWinsock();
    broker.createTopic("home/sensors/temperature");
    broker.createTopic("home/sensors/humidity");
    broker.createTopic("home/sensors/light");
}


TCPServer::~TCPServer() {
	stopServer();
	WSACleanup();
}

void TCPServer::initWinsock() {
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        throw std::runtime_error("WSAStartup failed");
    }
}

bool TCPServer::startServer(int port) {
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // Creating socket based on IPv4 and TCP
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Erro starting socket: " << WSAGetLastError() << std::endl;
        return false;
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        std::cerr << "Error while setting port: " << WSAGetLastError() << std::endl;
        return false;
    }

    listen(serverSocket, SOMAXCONN);
    std::cout << "Server started on port " << port << std::endl;
    return true;
}

void TCPServer::stopServer() {
    if (serverSocket != INVALID_SOCKET) {
        closesocket(serverSocket);
        serverSocket = INVALID_SOCKET;
    }
}


void TCPServer::acceptClients() {
    sockaddr_in client;
    int clientSize = sizeof(client);

    while (true) {
        SOCKET clientSocket = accept(serverSocket, (sockaddr*)&client, &clientSize);
        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Failed to accept client: " << WSAGetLastError() << std::endl;
            continue; 
        }

        std::thread([this, clientSocket]() { handleClient(clientSocket); }).detach();
    }
}

void TCPServer::handleClient(SOCKET clientSocket) {
    std::vector<unsigned char> buffer;
    while (true) {
        char tempBuffer[2048];
        memset(tempBuffer, 0, sizeof(tempBuffer));
        int bytesReceived = recv(clientSocket, tempBuffer, sizeof(tempBuffer), 0);

        if (bytesReceived > 0) {
            buffer.insert(buffer.end(), tempBuffer, tempBuffer + bytesReceived);

            // Process all complete messages in the buffer
            while (canProcessMessage(buffer)) {
                std::vector<unsigned char> message = extractMessage(buffer);
                broker.dispatchMessage(message, clientSocket);
            }
        }
        else if (bytesReceived == 0) {
            std::cout << "Client disconnected" << std::endl;
            break;
        }
        else {
            std::cerr << "Receive failed: " << WSAGetLastError() << std::endl;
            break;
        }
    }
}

bool TCPServer::canProcessMessage(const std::vector<unsigned char>& buffer) {
    if (buffer.size() < 2) return false; // Not enough data to read the fixed header and remaining length

    size_t index = 1; // Start after the fixed header's first byte
    int remainingLength = 0;
    int multiplier = 1;
    unsigned char encodedByte;

    do {
        if (index >= buffer.size()) return false; // Not enough data to decode remaining length
        encodedByte = buffer[index];
        remainingLength += (encodedByte & 127) * multiplier;
        multiplier *= 128;
        index++;
    } while ((encodedByte & 128) != 0 && index < buffer.size());

    return (index + remainingLength <= buffer.size()); // Check if the whole message is in buffer
}

std::vector<unsigned char> TCPServer::extractMessage(std::vector<unsigned char>& buffer) {
    size_t index = 1;
    int multiplier = 1;
    int remainingLength = 0;
    unsigned char encodedByte;

    do {
        encodedByte = buffer[index];
        remainingLength += (encodedByte & 127) * multiplier;
        multiplier *= 128;
        index++;
    } while ((encodedByte & 128) != 0);

    size_t totalLength = index + remainingLength; // Total message size
    std::vector<unsigned char> message(buffer.begin(), buffer.begin() + totalLength);
    buffer.erase(buffer.begin(), buffer.begin() + totalLength); // Remove the processed message
    return message;
}



void TCPServer::runServer() {
    std::cout << "Starting server for accepting clients" << std::endl;

    if (startServer(1883)) {
        acceptClients();
    }
}