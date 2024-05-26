#pragma once


#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include "Broker.h"


class TCPServer
{
public:
	TCPServer();
	~TCPServer();
	bool startServer(int port);
	void stopServer();
	void runServer();
	void acceptClients();
	void handleClient(SOCKET clientSocket);

private:
	SOCKET serverSocket;
	Broker broker;
	void initWinsock();
	
};

