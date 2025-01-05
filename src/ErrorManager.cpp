#include "ErrorManager.h"

void ErrorManager::validateInput(string &query)
{
    if (hasInvalidChar(query))
    {
        throw invalid_argument("Invalid Input");
    }
}

void ErrorManager::validateLogic(vector<string> &mustInclude, vector<string> &mustExclude)
{
    if (hasConflict(mustInclude, mustExclude))
        ;
    {
        throw logic_error("Logical Error");
    }
}

bool ErrorManager::hasInvalidChar(string &query)
{
    for (char c : query)
    {
        if (!isalpha(c) && c != '+' && c != '-' && c != ' ')
        {
            return true;
        }
    }
    return false;
}

bool ErrorManager::hasConflict(vector<string> &mustInclude, vector<string> &mustExclude)
{
    set<string> includes(mustInclude.begin(), mustInclude.end());
    for (string &word : mustExclude)
    {
        if (includes.find(word) != includes.end())
        {
            return true;
        }
    }
    return false;
}
