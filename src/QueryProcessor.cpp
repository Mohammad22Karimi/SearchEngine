#include "QueryProcessor.h"

vector<string> QueryProcessor::processQuery(string &query)
{
    QueryParts qp = paresQuery(query);
    set<string> mustContainDoc;
    set<string> mustExcludeDoc;
    set<string> mustIncludeDoc;

    if (!qp.mustContain.empty())
    {
        mustContainDoc = getDocuments(qp.mustContain[0]);
        // یافتن اشتراک برای کلمات باقیمانده
        for (size_t i = 1; i < qp.mustContain.size(); i++)
        {
            set<string> docs = getDocuments(qp.mustContain[i]);
            for (auto it = mustContainDoc.begin(); it != mustContainDoc.end();)
            {
                if (docs.find(*it) == docs.end())
                {
                    it = mustContainDoc.erase(it);
                }
                else
                {
                    ++it;
                }
            }
            if (mustContainDoc.empty())
            {
                break;
            }
        }
    }
    for (string &word : qp.mustInclude)
    {
        set<string> temp = getDocuments(word);
        mustIncludeDoc.insert(temp.begin(), temp.end());
    }
    for (string &word : qp.mustExclude)
    {
        set<string> temp = getDocuments(word);
        mustExcludeDoc.insert(temp.begin(), temp.end());
    }

    set<string> result;
    auto it1 = mustContainDoc.begin();
    auto it2 = mustIncludeDoc.begin();
    while (it1 != mustContainDoc.end() && it2 != mustIncludeDoc.end())
    {
        if (*it1 == *it2)
        {
            result.insert(*it1);
            ++it1;
            ++it2;
        }
        else if (*it1 < *it2)
        {
            ++it1;
        }
        else
        {
            ++it2;
        }
    }
    // if (!mustIncludeDoc.empty())
    // {
    //     result.insert(mustIncludeDoc.begin(), mustIncludeDoc.end());
    // }
    for (const string &doc : mustExcludeDoc)
    {
        result.erase(doc);
    }
    return vector<string>(result.begin(), result.end());
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
