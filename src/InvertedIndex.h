#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H
// ایجاد یک ایندکس که برای هر کلمه، لیستی از اسناد شامل آن کلمه را ذخیره کند
#pragma once
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include "Map.h"
#include <fstream>
#include "TextProcessor.h"
#include <algorithm>

class InvertedIndex
{
public:
    void addDocument(const string &doc, const string &value);
    vector<string> search(const string &query);

private:
    Map index;
    vector<string> fileList;
    vector<string> tokenize(const string &text);
};

#endif