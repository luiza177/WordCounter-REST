// #include "pistache/pistache.h"
#include "pistache/endpoint.h"

using namespace Pistache;

class HelloHandler : public Http::Handler
{
    HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response)
    {
        response.send(Http::Code::Ok, "Fuck you.");
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

//TODO: write GOOGLETEST template FILE
//TODO: TDD word library
//TODO: Understand pistache in terms of bottle
//TODO: TDD server
//TODO: TDD client
