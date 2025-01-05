#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#pragma once
#include <vector>
#include <string>
using namespace std;
class QueryProcessor
{
public:
    QueryProcessor();
    ~QueryProcessor();

private:
    class QueryParts
    {
        vector<string> mustInclude;
        vector<string> mustExclude;
        vector<string> mustContain;
    };
};

#endif