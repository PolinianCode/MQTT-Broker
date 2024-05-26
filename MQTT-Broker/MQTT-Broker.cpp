#include "TCPServer.h"

int main() {


    int port;
    std::cout << "Enter port for TCP server to start: " << std::endl;
    std::cin >> port;

    try {
        TCPServer server;
        if (server.startServer(port)) { 
            std::cout << "MQTT Broker running. Press Enter to stop." << std::endl;
            std::cin.get();
            server.stopServer();
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error while starting : " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
