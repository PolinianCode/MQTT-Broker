#pragma once


#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

class TCPServer
{
public:
	TCPServer();
	~TCPServer();
	bool startServer(int port);
	void stopServer();

private:
	SOCKET serverSocket;
	void initWinsock();
};

