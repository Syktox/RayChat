#include "Server/Server.h"


#define PORT 8080

int main() {
    auto* server = new Server(PORT);
    delete server;

    return 0;
}
