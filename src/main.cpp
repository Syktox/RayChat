#include "Server/Server.h"

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    auto* server = new Server(PORT);
    delete server;

    return 0;
}
