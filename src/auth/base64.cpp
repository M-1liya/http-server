#include "base64.hpp"


// Функция для кодирования данных в Base64
std::string base64::encode(const std::string &in) 
{
    std::string out;
    int val = 0;
    int valb = -6;

    for (unsigned char c : in) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            out.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) {
        out.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    }
    while (out.size() % 4) {
        out.push_back('=');
    }
    return out;
}

// Функция для декодирования данных из Base64
std::string base64::decode(const std::string &in) 
{ 

    if (in.length() % 4 != 0) 
    {
        throw std::runtime_error("Invalid Base64 input");
    }

    std::string out;
    std::vector<int> T(256, -1);

    for (int i = 0; i < 64; i++) 
    {
        T[base64_chars[i]] = i;
    }

    int val = 0;
    int valb = -8;
    for (unsigned char c : in) 
    {
        if (T[c] == -1) break;
        val = (val << 6) + T[c];
        valb += 6;
        if (valb >= 0) {
            out.push_back(char((val >> valb) & 0xFF));
            valb -= 8;
        }
    }
    return out;
}