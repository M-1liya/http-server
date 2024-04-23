#ifndef HTTP_SERVER_SERVER_HPP
#define HTTP_SERVER_SERVER_HPP

#include "HttpServer.h"
#include "Router.hpp"

class Server {
private:
    std::unique_ptr<hv::HttpServer> _server;
public:
    // constructor
    Server();
    // TODO: move constructor
    Server(const Server&) = delete;
    // TODO: copy assignment
    Server& operator=(const Server&) = delete;
    // TODO: move assignment
    Server& operator=(Server&) = delete;
    // destructor
    ~Server();

    void Start(int port, Router& router);
};

#endif //HTTP_SERVER_SERVER_HPP
