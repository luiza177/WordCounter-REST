#include <string>
#include <map>
#include <vector>

namespace WordCounter
{
    std::vector<std::string> separateIntoWords(std::string text)
    {
        std::istringstream textStream(text);
        auto wordVector = std::vector<std::string>(
            std::istream_iterator<std::string>(textStream), 
            std::istream_iterator<std::string>()
        );
        return wordVector;
    }
    
    void convertToLowerCase(std::vector<std::string>& words)
    {
        std::for_each(
            words.begin(),
            words.end(),
            [](std::string &word)
            {
                std::transform(word.begin(), word.end(), word.begin(), ::tolower);
            }
        );
    }

    /* std::map<std::string, int> analyzeWords(std::vector<std::string> words)
    {
    }
    
    std::map<std::string, int> analyzeWords(std::string words)
    {
    } */

    //TODO: eliminate non-alphanum
    //TODO: transfer into map for uniqueness?
}
