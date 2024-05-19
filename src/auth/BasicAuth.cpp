#include "BasicAuth.hpp"

User* BasicAuth::Authorize(const std::string& authorizationString, Storage& storage)
{
    base64 b64_coder = base64();
    User* user;

    std::vector<std::string> tmp = split(authorizationString, ' ');
    std::cout << "tmp[0] = " << tmp[0] << "\t tmp[1] = " << tmp[1] << std::endl;
    if(tmp[0] != "Basic") return nullptr;

    try
    {
        std::string authStr = b64_coder.decode(tmp[1]);
        std::vector<std::string> name_pass = split(authStr, ':');

        user = storage.GetUserByUsername(name_pass[0]);
        std::cout << user;
        std::cout << user->ComparePassword(name_pass[1]) << "\t pass = " << name_pass[1] << std::endl;
        if(user != nullptr && user->ComparePassword(name_pass[1]))
        {
            return user;
        }
    }
    catch(const std::exception& e)
    {
        return nullptr;
    }
    
    
    return nullptr;
}

std::vector<std::string> BasicAuth::split(const std::string& str, char delimiter)
 {
    std::vector<std::string> tokens;
    std::string token;
    std::stringstream ss(str);
    while (std::getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}