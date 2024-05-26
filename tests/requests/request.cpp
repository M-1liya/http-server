#include "request.hpp"
#include "requests.h"

ResponseData sendGetRequest(const std::string& url) 
{
    ResponseData response;

    requests::Response resp = requests::get(url.c_str());
    if (resp != nullptr) 
    {
        response.httpCode = resp->status_code;
        response.data = resp->body;
    } else 
    {
        response.httpCode = 0;
    }

    return response;
}