#ifndef ERRORMANAGER_H
#define ERRORMANAGER_H

#pragma once

#include <string>
#include <vector>
#include <set>
#include <stdexcept>
using namespace std;
class ErrorManager
{
public:
    void validateInput(string &query);
    void validateLogic(vector<string> &mustInclude, vector<string> &mustExclude);

private:
    bool hasInvalidChar(string &query);
    bool hasConflict(vector<string> &mustInclude, vector<string> &mustExclude);
};

#endif