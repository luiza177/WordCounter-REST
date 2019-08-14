#include <gtest/gtest.h>
#include "WordCounter.h"

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(WordCounter, CreatesVectorOfWords)
{
    auto text = std::string("Bebezinho bonitinho bebebol");
    
    auto words = WordCounter::separateIntoWords(text);
    
    ASSERT_EQ(words.size(), 3);
}

TEST(WordCounter, ConvertsAllWordsToLowerCase)
{
    auto text = std::string("BEBEbol");
    auto words = WordCounter::separateIntoWords(text);
    
    WordCounter::convertToLowerCase(words);
    
    ASSERT_EQ(words.at(0), "bebebol");
}

TEST(WordCounter, CreatesMapOfUniqueWords)
{
    auto text = std::string("Bebezinho bonitinho bebebol BEBEBOL");
    auto words = WordCounter::separateIntoWords(text);
   WordCounter::convertToLowerCase(words); 
    
    auto wordMap = WordCounter::analyzeWords(words);

    ASSERT_EQ(wordMap.at("bebebol"), 2);
}

TEST(WordCounter, EliminatesNonAlphaNumCharacters)
{
    auto text = std::string("BEBEbol, o anjinho");
    auto words = WordCounter::separateIntoWords(text);
    WordCounter::convertToLowerCase(words);
    WordCounter::removeNonAlphaNumeric(words);

    ASSERT_EQ(words.at(0), "bebebol");
}