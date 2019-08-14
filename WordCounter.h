#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cctype>

namespace WordCounter
{
    std::vector<std::string> separateIntoWords(const std::string& text)
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

    void removeNonAlphaNumeric(std::vector<std::string>& words)
    {
        std::for_each(
            words.begin(),
            words.end(),
            [](std::string &word)
            {
                word.erase(
                    std::remove_if(
                        word.begin(), 
                        word.end(), 
                        [](char& c)
                        {
                            return !::isalnum(c);
                        }
                    )
                );
            }
        );
    }

    std::map<std::string, int> analyzeWords(std::vector<std::string>& words)
    {
        std::map<std::string, int> wordMap;
        std::for_each(
            words.begin(),
            words.end(),
            [&](std::string word)
            {
                wordMap[word]++;
            }
        );
        return wordMap;
    }
    
    std::map<std::string, int> analyzeWords(std::string text)
    {
        auto wordVec = separateIntoWords(text);
        convertToLowerCase(wordVec);
        removeNonAlphaNumeric(wordVec);
        auto wordMap = analyzeWords(wordVec);
        return wordMap;
    }
}
