#include "QueryProcessor.h"

vector<string> QueryProcessor::processQuery(string &query)
{
    QueryParts qp = parseQuery(query);
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

    // ترکیب نهایی: اشتراک mustContainDocs و mustIncludeDocs
    set<string> result;

    if (!mustContainDoc.empty() && !mustIncludeDoc.empty())
    {
        set_intersection(mustContainDoc.begin(), mustContainDoc.end(),
                         mustIncludeDoc.begin(), mustIncludeDoc.end(),
                         inserter(result, result.begin()));
    }
    else if (!mustContainDoc.empty())
    {
        result = mustContainDoc;
    }
    else if (!mustIncludeDoc.empty())
    {
        result = mustIncludeDoc;
    }
    for (const string &doc : mustExcludeDoc)
    {
        result.erase(doc);
    }
    return vector<string>(result.begin(), result.end());
}

QueryProcessor::QueryParts QueryProcessor::parseQuery(string &query)
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
