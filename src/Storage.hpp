#ifndef HTTP_SERVER_STORAGE_HPP
#define HTTP_SERVER_STORAGE_HPP

#include "User.hpp"
#include <map>
#include <mutex>

class Storage {
private:
    std::map<std::string, User> _storage;
    std::mutex _mtx;

public:
    // constructor
    Storage();
    // TODO: move constructor
    Storage(const Storage&) = delete;
    // TODO: copy assignment
    Storage& operator=(const Storage&) = delete;
    // TODO: move assignment
    Storage& operator=(Storage&) = delete;
    // destructor
    ~Storage();

    std::string CreateUser(User& user);
    std::map<std::string, User>* GetUsers();
    User* GetUserByGuid(std::string& guid);
    bool UpdateUser(std::string& guid, const std::string& username, const std::string& email, const std::string& password);
    bool DeleteUser(std::string& guid);
};

#endif //HTTP_SERVER_STORAGE_HPP
