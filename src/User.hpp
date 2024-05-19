#ifndef HTTP_SERVER_USER_HPP
#define HTTP_SERVER_USER_HPP

#include <string>
#include <map>

class User {
private:
    std::string username;
    std::string email;
    std::string password;
    std::string isRoot = "false";
public:
    User() = default;
    User(std::string username, std::string email, std::string password);

    void ChangeUsername(const std::string& username);
    void ChangeEmail(const std::string& email);
    void ChangePassword(const std::string& password);
    void ChangeRole(bool IsRoot);
    std::string getUsername();
    bool ComparePassword(const std::string password);
    bool IsRoot();

    std::map<std::string, std::string> ToJson();
};

#endif //HTTP_SERVER_USER_HPP
