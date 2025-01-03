#include "TextProcessor.h"
#include <sstream>
#include <algorithm>
TextProcessor::TextProcessor()
{
}

TextProcessor::~TextProcessor()
{
}

vector<string> TextProcessor::clearnText(const string &text)
{
    string clearnText = text;
    clearnText.erase(remove_if(clearnText.begin(), clearnText.end(), ::ispunct), clearnText.end());
    transform(clearnText.begin(), clearnText.end(), clearnText.begin(), ::tolower);

    stringstream ss(clearnText);
    string word;
    vector<string> words;
    while (ss >> word)
    {
        words.push_back(word);
    }

    return words;
}
