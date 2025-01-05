#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#pragma once
#include <vector>
#include <string>
#include "InvertedIndex.h"
using namespace std;
class QueryProcessor
{
public:
    QueryProcessor(InvertedIndex &ind) : index(ind) {}
    ~QueryProcessor();

private:
    InvertedIndex index;

    class QueryParts
    {
    public:
        vector<string> mustInclude;
        vector<string> mustExclude;
        vector<string> mustContain;
    };
};

#endif