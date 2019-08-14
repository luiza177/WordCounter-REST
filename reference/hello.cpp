// #include "pistache/pistache.h"
#include "pistache/endpoint.h"

using namespace Pistache;

class HelloHandler : public Http::Handler
{
    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) override
    {
        if (request.resource() == "/") 
        {
            if (request.method() == Http::Method::Get) 
            {
                response.send(Http::Code::Ok, "<h1>Fuck you.</h1>");
            }
        }
        else if (request.resource() == "/fuck-you/:name")
        {

        }
        // else if (request.resource() == "/bleep/<times:int>") {}
        // else if (request.resource() == "/bleep/<name:path>") {}
        else if (request.resource() == "/login") 
        {
            if (request.method() == Http::Method::Get) 
            {
                response.send(Http::Code::Ok, 
                    R"(<form action="/login" method="post">
                    Username: <input name="username" type="text" />
                    Password: <input name="password" type="password" />
                    <input value="Login" type="submit" />
                    </form>)");
            }
            else if (request.method() == Http::Method::Post)
            {
                response.send(Http::Code::Ok, "<h2>Hah.</h2>");
            }
        }
        else 
        {
            response.send(Http::Code::Not_Found, "404 - NOT FOUND!"); 
        }
    }
};

int main(int argc, char const *argv[])
{
    Pistache::Address addr(Pistache::Ipv4::any(), Pistache::Port(9080));

    /* auto opts = Http::Endpoint::options().threads(1);
    Http::Endpoint server(addr);
    server.init(opts);
    server.setHandler(std::make_shared<HelloHandler>());
    server.serve(); */

    Http::listenAndServe<HelloHandler>("*:9080");
    return 0;
}

//TODO: TDD server
//TODO: TDD client