#include "TextProcessor.h"
#include <sstream>
#include <algorithm>

vector<string> TextProcessor::cleanText(const string &text)
{
    string cl = text;
    cl.erase(remove_if(cl.begin(), cl.end(), ::ispunct), cl.end());
    transform(cl.begin(), cl.end(), cl.begin(), ::tolower);

    stringstream ss(cl);
    string word;
    vector<string> words;
    while (ss >> word)
    {
        words.push_back(word);
    }

    return words;
}
