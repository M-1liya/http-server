#include <iostream>
#include "Server.hpp"
#include "Router.hpp"

int main() {
    std::cout << "Hello, world" << std::endl;

    Router router = Router();

    Server srv = Server();
    srv.Start(8080, router);

    return 0;
}