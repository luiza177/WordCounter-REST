#include <iostream>
#include <string>
#include "cpr/cpr.h"
#include "json.hpp"

class WordCounterClient
{
private:
    std::string m_text = "guinho lucy ball bebe bebe";
    nlohmann::json m_jsonWordAnalysis;
    nlohmann::json m_jsonText;
public:
    WordCounterClient(){}
    ~WordCounterClient(){}
    bool getWordAnalysis()
    {
        m_jsonText["text"] = m_text;
        auto r = cpr::Post(cpr::Url{"localhost:9080/contagem"}, 
            cpr::Body{m_jsonText.dump()}, 
            cpr::Header{{"Content-Type", "application/json"}});
        
        if (r.status_code == 200)
        {
            m_jsonWordAnalysis = nlohmann::json::parse(r.text); 
            return true;
        }
        std::cerr << "Something went wrong.\n";
        return false;
    }
    void displayWordAnalysis()
    {
        std::cout << m_jsonWordAnalysis.dump() << std::endl;
    }
};
