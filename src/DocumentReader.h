#ifndef DOCUMENTREADER_H
#define DOCUMENTREADER_H
// خواندن فایل‌های متنی از پوشه
#pragma once

#include <string>
#include <vector>
#include <utility>
using namespace std;
class DocumentReader
{
public:
    DocumentReader();
    vector<pair<string, string>> readDocument(const string &filePath);
    ~DocumentReader();

private:
};

#endif