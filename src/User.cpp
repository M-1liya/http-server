#include "User.hpp"
#include <iostream>

User::User(std::string username, std::string email="user@gmail.com", std::string password="q1w2e3")
    : username(std::move(username)), email(std::move(email)), password(std::move(password)) {

}

User::~User()
{
}

std::map<std::string, std::string> User::ToJson() {
    return std::map<std::string, std::string> {
        std::pair{"username", this->username},
        std::pair{"email", this->email},
        std::pair{"password", this->password},
        std::pair{"role", this->isRoot}
    };
}

void User::ChangeUsername(const std::string& usrnm) {
    this->username = usrnm;
}
void User::ChangeEmail(const std::string& em) {
    this->email = em;
}
void User::ChangePassword(const std::string& pswd) {
    this->password = pswd;
}
void User::ChangeRole(bool IsRoot)
{
    this->isRoot = IsRoot ? "true" : "false";
}
std::string User::getUsername()
{
    return this->username;
}
bool User::ComparePassword(const std::string _password)
{
    std::cout << _password << " <> " << _password << std::endl;
    return _password == this->password;
}

bool User::IsRoot()
{
    return this->isRoot == "true";
}

std::string User::getPassword()
{
    return this->password;
}
