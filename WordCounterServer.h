#include <pistache/endpoint.h>
#include <pistache/router.h>
#include "json.hpp"
#include "WordCounter.h"

using namespace Pistache;

class WordCounterServer
{
private:
    std::shared_ptr<Http::Endpoint> httpEndpoint;
    Rest::Router router;
    
    void setupRoutes() 
    {
        using namespace Rest;

        Routes::Post(router, "/contagem", Routes::bind(&WordCounterServer::doWordCount, this));
    }

    void doWordCount(const Rest::Request& request, Http::ResponseWriter response)
    {
        // check headers?
        // get body
        // do json
        nlohmann::json inputJson = nlohmann::json::parse(request.body());
        if (inputJson.find("text") != inputJson.end())
        {
            nlohmann::json responseJson = WordCounter::analyzeWords(inputJson.at("text"));
            response.send(Http::Code::Ok, responseJson.dump());
        }
    }
public:
    WordCounterServer(Address addr) : httpEndpoint(std::make_shared<Http::Endpoint>(addr)) {}

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
