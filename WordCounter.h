#include <string>
#include <map>
#include <vector>

namespace WordCounter
{
    std::vector<std::string> separateIntoWords(std::string text)
    {
        auto wordVector = std::vector<std::string>();
        std::istringstream textStream(text);
        std::copy(std::istream_iterator<std::string>(textStream), 
            std::istream_iterator<std::string>(), 
            std::back_inserter(wordVector)
        );
        return wordVector;
    }
}
