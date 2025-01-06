#include <iostream>
#include "DocumentReader.cpp"
#include "InvertedIndex.cpp"
#include "TextProcessor.cpp"
#include "Map.cpp"
#include "QueryProcessor.cpp"
using namespace std;
int main()
{
    string folderPath;
    cout << "Enter the folder path of the documents: ";
    getline(cin, folderPath);
    //"C:/Users/Karimi/Desktop/search engine/ui-ds-02-project01-searchengine-Mohammad22Karimi-1/EnglishData"
    int n;
    cout << "Enter the number of queries :";
    cin >> n;
    cin.ignore();
    DocumentReader reader;
    vector<pair<string, string>> documents = reader.readDocument(folderPath);

    InvertedIndex index;
    for (const auto &doc : documents)
    {
        index.addDocument(doc.second, doc.first);
    }
    QueryProcessor processor(index);

    while (n > 0, n--)
    {
        cout << "Enter search query : ";
        string query;
        getline(cin, query);
        transform(query.begin(), query.end(), query.begin(), ::tolower);

        bool exception = false;
        vector<string> results = processor.processQuery(query, exception);
        if (exception)
        {
            continue;
        }
        if (results.empty())
        {
            cout << "No results found for \"" << query << "\"." << endl;
        }
        else
        {
            cout << results.size() << endl;
            for (const auto &doc : results)
            {
                cout << doc << endl;
            }
        }
    }

    return 0;
}
