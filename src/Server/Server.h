#pragma once
#include <sys/socket.h>
#include <netinet/in.h>

class Server {
private:
    int _serverSocket;
    sockaddr_in _address{};
    int _socket;
private:
    int acceptConnection();
public:
    explicit Server(int PORT);
    ~Server();
};
