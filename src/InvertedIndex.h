#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H
// ایجاد یک ایندکس که برای هر کلمه، لیستی از اسناد شامل آن کلمه را ذخیره کند
#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include "Map.h"
class InvertedIndex
{
public:
    InvertedIndex();

    void addDocument(const string &doc);
    vector<string> search(const string &query);
    ~InvertedIndex();

private:
    Map index;
    vector<string> tokenize(const string &text);
};

#endif