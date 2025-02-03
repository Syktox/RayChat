#include "Server.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

Server::Server(int PORT) {
    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (_serverSocket == 0) exit(EXIT_FAILURE);

    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = INADDR_ANY;
    _address.sin_port = htons(PORT);

    if (bind(_serverSocket, (struct sockaddr*)& _address, sizeof(_address)) < 0) {
        exit(EXIT_FAILURE);
    }

    std::cout << "Waiting for connection " << PORT << "..." << std::endl;

    if (listen(_serverSocket, 5) < 0) {  // Backlog queue set to 5
        std::cerr << "Listen failed" << std::endl;
        close(_serverSocket);
    }

    _socket = acceptConnection();

    if (_socket < 0) exit(EXIT_FAILURE);
}

Server::~Server() {
    close(_socket);
    close(_serverSocket);
}

int Server::acceptConnection() {
    auto addrlen = sizeof(_address);
    return accept(_serverSocket, (struct sockaddr*)&_address, (socklen_t*)& addrlen);
}

