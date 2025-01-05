#ifndef QUERYPROCESSOR_H
#define QUERYPROCESSOR_H

#pragma once
#include <vector>
#include <string>
#include "InvertedIndex.h"
#include <set>
using namespace std;
class QueryProcessor
{
public:
    QueryProcessor(InvertedIndex &ind) : index(ind) {}
    vector<string> processQuery(string &query);

private:
    InvertedIndex index;

    class QueryParts
    {
    public:
        vector<string> mustInclude;
        vector<string> mustExclude;
        vector<string> mustContain;
    };

    QueryParts parseQuery(string &query);
    set<string> getDocuments(string &word);
};

#endif