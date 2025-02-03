#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <thread>

class Server {
private:
    int _serverSocket;
    sockaddr_in _address{};
    int _socket;
    std::vector<std::thread> thread_list;

private:
    int acceptConnection();
public:
    explicit Server(int PORT);
    ~Server();
};
