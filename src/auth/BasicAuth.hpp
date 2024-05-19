
#include <string>
#include <sstream>
#include <vector>
#include "base64.hpp"
#include "../Storage.hpp"


class BasicAuth {
private:
    std::vector<std::string> split(const std::string& str, char delimiter);
public:
    BasicAuth() = default;

    User* Authorize(const std::string& authorizationString, Storage& storage);


};

