#include <pistache/endpoint.h>
#include <pistache/router.h>
#include <functional>
using namespace Pistache;

class Bottle
{
private:
    std::shared_ptr<Http::Endpoint> httpEndpoint;
    Rest::Router router;
    std::map<std::string, std::string> m_loginBank = { {"dolha", "guinho"} };
    
    void setupRoutes() 
    {
        using namespace Rest;

        Routes::Get(router, "/", Routes::bind(&Bottle::hello, this));
        Routes::Get(router, "/bleep/:name", Routes::bind(&Bottle::bleep, this));
        Routes::Get(router, "/fuck-you/:name", Routes::bind(&Bottle::fuckYou, this));
        Routes::Get(router, "/login", Routes::bind(&Bottle::login, this));
        Routes::Post(router, "/login", Routes::bind(&Bottle::login, this));
        
        //TODO: Customize 404 error?
    }

    void hello(const Rest::Request& request, Http::ResponseWriter response)
    {
        response.send(Http::Code::Ok, "<h1>Fuck you.</h1>");
    }

    void fuckYou(const Rest::Request& request, Http::ResponseWriter response)
    {

        auto name = request.param(":name").as<std::string>();
        auto text = "<h2>Fuck you, " + name + ".</h2>";
        response.send(Http::Code::Ok, text);
    }

    void bleep(const Rest::Request& request, Http::ResponseWriter response)
    {
        if (request.hasParam(":name")) 
        {
            auto name = request.param(":name").as<std::string>();
            auto text = "<h2>Hey " + name + ", bleep you.</h2>";
            auto times = 1;
            try
            {
                times = stoi(name);
                text = "";
                for (int i = 0; i < times; ++i) text += "fuck you ";
            }
            catch (std::exception e)
            {
                std::cout << "/bleep/:name : Not an integer number.\n";    
            }
            response.send(Http::Code::Ok, text);
        }
    }

    void login(const Rest::Request& request, Http::ResponseWriter response)
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
            try 
            {
                auto creds = nodeParser(request.body());
                if (validateLogin(creds.at(0), creds.at(1)))
                    response.send(Http::Code::Ok, "<h3>Your login info was correct.</h3>");
                else
                    response.send(Http::Code::Ok, "<h4>Your password was incorrect.</h4>");
            }
            catch (std::exception e)
            {
                response.send(Http::Code::Ok, "<h4>No such username.</h4>");
            }
            // response.send(Http::Code::Ok, "<h2>Hah.</h2>");
        }
    }

    bool validateLogin(std::string username, std::string passwd)
    {
        return m_loginBank.at(username) == passwd;
    }
    
    std::vector<std::string> nodeParser(std::string body)
    {
        std::vector<std::string> result;
        auto ampPos = body.find('&');
        auto un = body.substr(0, ampPos);
        auto pw = body.substr(ampPos + 1);
        
        auto eqPos = un.find('=');
        auto username = un.substr(eqPos + 1);
        
        eqPos = pw.find('=');
        auto passwd = pw.substr(eqPos + 1);

        result.push_back(username);
        result.push_back(passwd);
        return result;
    }
    

public:
    Bottle(Address addr) : httpEndpoint(std::make_shared<Http::Endpoint>(addr)) {}

    void init(size_t thr = 2) {
        auto opts = Http::Endpoint::options()
            .threads(thr);
        httpEndpoint->init(opts);
        setupRoutes();
    }

    void start() {
        httpEndpoint->setHandler(router.handler());
        httpEndpoint->serve();
    }

};

int main(int argc, char const *argv[])
{
    Address addr(Ipv4::any(), Port(9080));

    Bottle server(addr);
   
    server.init();
    server.start();

    return 0;
}