#include "TCPServer.h"


#pragma comment(lib, "Ws2_32.lib")

TCPServer::TCPServer() :serverSocket(INVALID_SOCKET) {
	initWinsock();
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
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Failed to create socket: " << WSAGetLastError() << std::endl;
        return false;
    }

    sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR) {
        std::cerr << "Bind failed: " << WSAGetLastError() << std::endl;
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