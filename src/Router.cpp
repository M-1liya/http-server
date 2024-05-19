#include "Router.hpp"
#include <vector>

Router::Router() {
    _router = std::make_unique<hv::HttpService>();
    RegisterRoutes();
}

Router::~Router() {
    delete &_router;
}

hv::HttpService* Router::GetHttpService() {
    return &(*_router);
}

void Router::RegisterRoutes() {

    
    _router->POST("/signup", [this](HttpRequest *req, HttpResponse *resp) {
        hv::Json request = req->GetJson();

        std::string username;
        std::string email;
        std::string password;

        
        std::cout << request << std::endl;

        try {
            username = request["username"];
            email = request["email"];
            password = request["password"];
        }
        catch (const std::exception& e) {
            hv::Json response
            {
                { "message", "fill in all fields to create a user (fields: username, email, password)" }
            };
            resp->Json(response);
            return 400;
        }

        User createdUser = User(username, email, password);
        std::string guid = this->_storage.CreateUser(createdUser);

        hv::Json response {
            { guid, createdUser.ToJson() }
        };
        resp->Json(response);

        return 200;
    });

    _router->GET("/signin", [](HttpRequest *req, HttpResponse *resp) {
        // TODO: implement me
        return 200;
    });

    _router->GET("/logout", [](HttpRequest *req, HttpResponse *resp) {
        // TODO: implement me
        return 200;
    });

    _router->GET("/users", [this](HttpRequest *req, HttpResponse *resp) {
        auto users = this->_storage.GetUsers();

        if (users->empty()) {
            hv::Json response
            {
                { "message", "no users found" }
            };
            resp->Json(response);
            return 200;
        }

        hv::Json response;

        for (auto &user : *users) {
            response.push_back({user.first, user.second.ToJson()});
        }

        resp->Json(response);
        return 200;
    });

    _router->GET("/users/{guid}", [this](HttpRequest *req, HttpResponse *resp) {
        std::string guid = req->GetParam("guid");

        if (guid == hv::empty_string) {
            hv::Json response
            {
                { "message", "guid is empty" }
            };
            resp->Json(response);
            return 400;
        }

        auto user = this->_storage.GetUserByGuid(guid);

        if (user == nullptr) {
            hv::Json response
            {
                { "message", "no user found" }
            };
            resp->Json(response);
            return 404;
        }

        hv::Json response {
            { guid, user->ToJson() }
        };
        resp->Json(response);
        return 200;
    });

    _router->PATCH("/users/{guid}", [this](HttpRequest *req, HttpResponse *resp) {

        hv::Json request = req->GetJson();

        std::string authorization;        
        std::cout << request << std::endl;

        //Getting authoriztaion string
        try 
        {
            authorization = request["authoriztaion"];
        }
        catch (const std::exception& e) {
            hv::Json response
            {
                { "message", "Need autoriztaion field for patch anything" }
            };
            resp->Json(response);
            return 400;
        }
        std::cout << "Authorization string = " << authorization << std::endl;

        User* ReqUser;
        //Verification of autoriztaion
        try
        {
            ReqUser = authorizator.Authorize(authorization, _storage);
            if(ReqUser == nullptr)
            {
                hv::Json response
                {
                    { "message", "invalid username or password" }
                };
                resp->Json(response);
                return 400;
            }
        }
        catch(const std::exception& e)
        {
            hv::Json response
            {
                { "message", "invalid username or password" }
            };
            resp->Json(response);
            return 400;
        }
        

        std::string guid = req->GetParam("guid");
        std::cout << "Giud: " << guid << std::endl;

        if (guid == hv::empty_string) {
            hv::Json response
            {
                { "message", "guid is empty" }
            };
            resp->Json(response);
            return 400;
        }


        if(_storage.GetUserGuidByUsername(ReqUser->getUsername()) != guid && !ReqUser->IsRoot())
        {
            hv::Json response
            {
                { "message", "Not enough rights" }
            };
            resp->Json(response);
            return 400;
        }

        

        std::string username;
        std::string email;
        std::string password;

        try {
            username = request["username"];
        }
        catch (const std::exception& e) {
            username = "";
        }

        try {
            email = request["email"];
        }
        catch (const std::exception& e) {
            email = "";
        }

        try {
            password = request["password"];
        }
        catch (const std::exception& e) {
            password = "";
        }

        if (username.empty() && email.empty() && password.empty()) {
            hv::Json response
            {
                { "message", "nothing to update" }
            };
            resp->Json(response);
            return 400;
        }

        std::cout << username << " | " << email << " | " << password << std::endl;

        bool isGood = this->_storage.UpdateUser(guid, username, email, password);

        if (!isGood) {
            hv::Json response
            {
                { "message", "no user found" }
            };
            resp->Json(response);
            return 404;
        }

        hv::Json response
        {
            { "message", "success" }
        };
        resp->Json(response);

        return 200;
    });

    _router->Delete("/users/{guid}", [this](HttpRequest *req, HttpResponse *resp) {
        std::string guid = req->GetParam("guid");

        if (guid == hv::empty_string) {
            hv::Json response
            {
                { "message", "guid is empty" }
            };
            resp->Json(response);
            return 400;
        }

        bool isGood = this->_storage.DeleteUser(guid);

        if (!isGood) {
            hv::Json response
            {
                { "message", "no user found" }
            };
            resp->Json(response);
            return 404;
        }

        return 200;
    });
}