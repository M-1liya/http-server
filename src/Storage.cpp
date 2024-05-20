#include "Storage.hpp"
#include <map>
#include <iostream>

Storage::Storage() {
    _storage = std::map<std::string, User>();

    User rootUser =  User("root", "root@root.ru", "root");
    rootUser.ChangeRole(true); //Is root?

    std::lock_guard<std::mutex> guard(_mtx);
    _storage["rootrootrootrootroot"] = rootUser;
}

Storage::~Storage() {
    delete &_storage;
}

std::string Storage::CreateUser(User& user) {
    std::lock_guard<std::mutex> guard(_mtx);

    // TODO: move to other package
    static std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
    std::string result;
    result.resize(20);

    srand(time(nullptr));
    for (int i = 0; i < 20; i++) {
        if (i % 5 == 0 && i > 0) {
            result[i] = '-';
        } else {
            result[i] = charset[rand() % charset.length()];
        }
    }

    std::string guid = result;

    _storage[guid] = user;

    return guid;
}

std::map<std::string, User>* Storage::GetUsers() {
    std::lock_guard<std::mutex> guard(_mtx);

    return &_storage;
}

User* Storage::GetUserByGuid(const std::string& guid) {
    std::lock_guard<std::mutex> guard(_mtx);

    if (_storage.count(guid) > 0) {
        return &_storage[guid];
    }

    return nullptr;
}

std::string Storage::GetUserGuidByUsername(const std::string &username)
{
    for(auto& [guid, user] : _storage)
    {

        if(user.getUsername() == username)
        {
            std::cout << "!!! NasheL GUID!!!" << std::endl;
            return guid;
        }
        std::cout << user.getUsername() << "!=" << username << std::endl;
    }




    return nullptr;
}

User* Storage::GetUserByUsername(const std::string& uName) {
    std::lock_guard<std::mutex> guard(_mtx);


    for(auto& [guid, user] : _storage)
    {

        if(user.getUsername() == uName)
        {
            std::cout << "!!! NasheL !!!" << std::endl;
            return &user;
        }
        std::cout << user.getUsername() << "!=" << uName << std::endl;
    }

    std::cout << "Ne nashel" << std::endl;
    return nullptr;
}

bool Storage::UpdateUser(std::string& guid, const std::string& username, const std::string& email, const std::string& password) {
    std::lock_guard<std::mutex> guard(_mtx);

    if (_storage.count(guid) > 0) {
        if (!username.empty()) {
            _storage[guid].ChangeUsername(username);
        }
        if (!email.empty()) {
            _storage[guid].ChangeEmail(email);
        }
        if (!password.empty()) {
            _storage[guid].ChangePassword(password);
        }

        return true;
    }

    return false;
}

bool Storage::DeleteUser(std::string& guid) {
    std::lock_guard<std::mutex> guard(_mtx);

    size_t x = _storage.erase(guid);

    if (x > 0) {
        return true;
    }

    return false;
}