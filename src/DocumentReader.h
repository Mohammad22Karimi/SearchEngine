#ifndef DOCUMENTREADER_H
#define DOCUMENTREADER_H
// خواندن فایل‌های متنی از پوشه
#pragma once

#include <string>
#include <vector>
#include <utility>
#include "InvertedIndex.h"
using namespace std;
class DocumentReader
{
public:
    vector<pair<string, string>> readDocument(const string &filePath);

private:
};

#endif