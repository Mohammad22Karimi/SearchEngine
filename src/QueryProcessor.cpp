#include "QueryProcessor.h"

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
