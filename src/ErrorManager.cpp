#include "ErrorManager.h"

void ErrorManager::validateInput(string &query)
{
    if (hasInvalidChar(query))
    {
        throw invalid_argument("Invalid Input");
    }
}

void ErrorManager::validateLogic(vector<string> &mustInclude, vector<string> &mustExclude, vector<string> &mustContain)
{
    if (hasConflict(mustInclude, mustExclude, mustContain))
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

bool ErrorManager::hasConflict(vector<string> &mustInclude, vector<string> &mustExclude, vector<string> &mustContain)
{
    set<string> includes(mustInclude.begin(), mustInclude.end());
    set<string> Contain(mustContain.begin(), mustContain.end());
    for (string &word : mustExclude)
    {
        if ((includes.find(word) != includes.end()) || (Contain.find(word) != Contain.end()))
        {
            return true;
        }
    }
    return false;
}
