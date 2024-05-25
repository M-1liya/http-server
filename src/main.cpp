#include <iostream>
#include "Server.hpp"
#include "Router.hpp"

int main() {
    std::cout << "Server has been started" << std::endl;

    Router router;

    Server srv;
    srv.Start(8080, router);

    return 0;
}