#include "TCPServer.h"
#include "Broker.h"
#include <thread>


#pragma comment(lib, "Ws2_32.lib")

TCPServer::TCPServer() :serverSocket(INVALID_SOCKET) {
	initWinsock();
    broker.createTopic("home/sensors/temperature");
    broker.createTopic("home/sensors/humidity");
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
    try {
        while (true) {
            char buffer[1024];
            memset(buffer, 0, sizeof(buffer));
            int bytesReceived = recv(clientSocket, buffer, 1024, 0);

            if (bytesReceived > 0) {
                std::cout << "Received data: " << buffer << std::endl;

                std::vector<unsigned char> message(buffer, buffer + bytesReceived);
                broker.dispatchMessage(message, clientSocket);
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
    catch (const std::exception& e) {
        std::cerr << "Exception handling client: " << e.what() << std::endl;
    }

    closesocket(clientSocket);
}


void TCPServer::runServer() {
    std::cout << "Starting server for accepting clients" << std::endl;

    if (startServer(1883)) {
        acceptClients();
    }
}