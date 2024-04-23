#ifndef HTTP_SERVER_ROUTER_HPP
#define HTTP_SERVER_ROUTER_HPP

#include "HttpService.h"
#include "Storage.hpp"

class Router {
private:
    std::unique_ptr<hv::HttpService> _router;
    Storage _storage = Storage();

    void RegisterRoutes();
public:
    // constructor
    Router();
    // TODO: move constructor
    Router(const Router&) = delete;
    // TODO: copy assignment
    Router& operator=(const Router&) = delete;
    // TODO: move assignment
    Router& operator=(Router&) = delete;
    // destructor
    ~Router();

    hv::HttpService* GetHttpService();
};

#endif //HTTP_SERVER_ROUTER_HPP
