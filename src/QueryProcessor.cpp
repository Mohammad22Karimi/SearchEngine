#include "QueryProcessor.h"

vector<string> QueryProcessor::processQuery(string &query)
{
    QueryParts qp = paresQuery(query);
    set<string> mustContainDoc;
    set<string> mustExcludeDoc;
    set<string> mustIncludeDoc;
}

QueryProcessor::QueryParts QueryProcessor::paresQuery(string &query)
{
    QueryParts qp;
    stringstream queryStream(query);
    string word;

    while (queryStream >> word)
    {
        if (word[0] == '+')
        {
            qp.mustInclude.push_back(word.substr(1));
        }
        else if (word[0] == '-')
        {
            qp.mustExclude.push_back(word.substr(1));
        }
        else
        {
            qp.mustContain.push_back(word);
        }
    }
    return qp;
}

set<string> QueryProcessor::getDocuments(string &word)
{
    vector<string> documents = index.search(word);
    return set<string>(documents.begin(), documents.end());
}
