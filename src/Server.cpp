#include "Server.hpp"
#include <thread>

Server::Server() {
    _server = std::make_unique<hv::HttpServer>();
}

void Server::Start(int port, Router& router) {
    _server->setPort(port);
    _server->registerHttpService(router.GetHttpService());
    _server->setThreadNum(std::thread::hardware_concurrency());
    _server->run();
}

Server::~Server() {
    _server->stop();
}
