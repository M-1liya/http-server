#include "User.hpp"

User::User(std::string username, std::string email="user@gmail.com", std::string password="q1w2e3")
    : username(std::move(username)), email(std::move(email)), password(std::move(password)) {

}

std::map<std::string, std::string> User::ToJson() {
    return std::map<std::string, std::string> {
        std::pair{"username", this->username},
        std::pair{"email", this->email},
        std::pair{"password", this->password}
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