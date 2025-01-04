#include "InvertedIndex.h"

InvertedIndex::InvertedIndex()
{
}

void InvertedIndex::addDocument(const string &doc)
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
            index.insert(word, doc); // اضافه کردن به ایندکس
        }
    }

    fileP.close();
}

InvertedIndex::~InvertedIndex()
{
}