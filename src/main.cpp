#include <iostream>
#include "DocumentReader.cpp"
#include "InvertedIndex.cpp"
#include "TextProcessor.cpp"
#include "Map.cpp"
using namespace std;
int main()
{
    string folderPath;
    cin >> folderPath;
    //"C:/Users/Karimi/Desktop/search engine/ui-ds-02-project01-searchengine-Mohammad22Karimi-1/EnglishData"

    DocumentReader reader;
    vector<pair<string, string>> documents = reader.readDocument(folderPath);

    InvertedIndex index;
    for (const auto &doc : documents)
    {
        index.addDocument(doc.second, doc.first);
    }
    while (true)
    {
        cout << "Enter search query (or type 'exit' to quit): ";
        string query;
        getline(cin, query);

        if (query == "exit")
            break;

        // جستجوی کوئری در ایندکس
        vector<string> results = index.search(query);

        if (results.empty())
        {
            cout << "No results found for \"" << query << "\"." << endl;
        }
        else
        {
            cout << "Results for \"" << query << "\":" << endl;
            for (const string &doc : results)
            {
                cout << "- " << doc << endl;
            }
        }
    }

    return 0;
}
