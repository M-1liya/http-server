#include <gtest/gtest.h>
#include <hv/HttpClient.h>
#include "/home/user/projects/http-server/src/auth/base64.hpp"
#include "requests/request.hpp"

TEST (SmokeTest, SuccessfulGetRequest)
{
    ResponseData response = sendGetRequest("localhost:8080/users");

    EXPECT_EQ(response.httpCode, 200);
}

TEST (UnitTest, Encodind_base64)
{
    base64 coder;
    
    EXPECT_EQ(coder.encode("hi:64"), "aGk6NjQ=");
    EXPECT_EQ(coder.decode("aGk6NjQ="), "hi:64");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}