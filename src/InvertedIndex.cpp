#include "InvertedIndex.h"

void InvertedIndex::addDocument(const string &doc, const string &value)
{
    ifstream fileP(doc, ios::in);

    if (!fileP)
    {
        cerr << "Error opening file: " << doc << endl;
        return;
    }

    if (find(fileList.begin(), fileList.end(), doc) != fileList.end())
    {
        cerr << "File already indexed: " << doc << endl;
        return;
    }

    fileList.push_back(doc);
    string line;

    TextProcessor processor;

    while (getline(fileP, line))
    {

        vector<string> words = processor.cleanText(line);

        for (string &word : words)
        {

            index.insert(word, value);
        }
    }

    fileP.close();
}

vector<string> InvertedIndex::tokenize(const string &text)
{
    vector<string> tokens;
    stringstream ss(text);
    string word;

    while (ss >> word)
    {
        tokens.push_back(word);
    }
    return tokens;
}
vector<string> InvertedIndex::search(const string &query)
{ // باید لیست اسناد مرتبط با کلمه را بازگرداند
    vector<string> results;
    vector<string> words = tokenize(query);
    for (string &word : words)
    {
        vector<string> docList = index.get(word);

        results.insert(results.end(), docList.begin(), docList.end());
    }
    return results;
}
