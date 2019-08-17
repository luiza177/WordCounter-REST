#include "WordCounterClient.h"


int main(int argc, char const *argv[])
{
    WordCounterClient wordCounterClient;
    if (wordCounterClient.getWordAnalysis())
        wordCounterClient.displayWordAnalysis();

    return 0;
}
