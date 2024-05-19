
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>


class base64 
{

private:
    const std::string base64_chars = 
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";
public:
    base64() = default;
    std::string encode(const std::string &in);
    std::string decode(const std::string &in);
};

