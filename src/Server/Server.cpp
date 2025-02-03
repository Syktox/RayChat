#include "Server.h"
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

const char* htmlResponse =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Connection: close\r\n"
        "\r\n"
        "<!DOCTYPE html>"
        "<html lang='de'>"
        "<head>"
        "<meta charset='UTF-8'>"
        "<meta name='viewport' content='width=device-width, initial-scale=1.0'>"
        "<title>Messagebox</title>"
        "<script>"
        "window.onload = function() {"
        "   alert('Willkommen auf dem C++-Server!');"
        "};"
        "</script>"
        "</head>"
        "<body><h1>Hallo! Dein C++-Socket-Server läuft.</h1></body>"
        "</html>";


Server::Server(int PORT) {
    _serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (_serverSocket == 0) exit(EXIT_FAILURE);

    int opt = 1;
    setsockopt(_serverSocket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    _address.sin_family = AF_INET;
    _address.sin_addr.s_addr = inet_addr("192.168.76.117");
    _address.sin_port = htons(PORT);

    if (bind(_serverSocket, (struct sockaddr*)& _address, sizeof(_address)) < 0) {
        exit(EXIT_FAILURE);
    }

    std::cout << "Waiting for connection " << PORT << "..." << std::endl;

    if (listen(_serverSocket, 5) < 0) {  // Backlog queue set to 5
        std::cerr << "Listen failed" << std::endl;
        close(_serverSocket);
    }


    while (true) {
        _socket = acceptConnection();
        if (_socket < 0) {
            std::cerr << "Verbindung fehlgeschlagen" << std::endl;
            continue;
        }

        send(_socket, htmlResponse, strlen(htmlResponse), 0);
        close(_socket);
    }



    if (_socket < 0) exit(EXIT_FAILURE);


    else std::cout << "Success\n";
}

Server::~Server() {
    close(_socket);
    close(_serverSocket);
}

int Server::acceptConnection() {
    auto addrlen = sizeof(_address);
    return accept(_serverSocket, (sockaddr*)&_address, (socklen_t*)& addrlen);
}

