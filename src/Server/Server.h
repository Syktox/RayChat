#pragma once
#include <sys/socket.h>
#include <netinet/in.h>
#include <vector>
#include <thread>
#include "../../include/json.hpp"

class Server {
private:
    int _serverSocket;
    sockaddr_in _address{};
    int _socket;
    std::vector<std::thread> thread_list;
    nlohmann::json _json;

private:
    int acceptConnection();
public:
    explicit Server(int PORT);
    ~Server();
};
