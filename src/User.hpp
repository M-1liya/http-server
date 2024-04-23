#ifndef HTTP_SERVER_USER_HPP
#define HTTP_SERVER_USER_HPP

#include <string>
#include <map>

class User {
private:
    std::string username;
    std::string email;
    std::string password;
public:
    User() = default;
    User(std::string username, std::string email, std::string password);

    void ChangeUsername(const std::string& username);
    void ChangeEmail(const std::string& email);
    void ChangePassword(const std::string& password);

    std::map<std::string, std::string> ToJson();
};

#endif //HTTP_SERVER_USER_HPP
