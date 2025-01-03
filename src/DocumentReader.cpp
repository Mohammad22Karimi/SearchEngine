#include "DocumentReader.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

DocumentReader::DocumentReader()
{
}

vector<pair<string, string>> DocumentReader::readDocument(const string &filePath)
{
    vector<pair<string, string>> doc;

    for (auto &entry : fs::directory_iterator(filePath))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".txt")
        {
            string fileName = entry.path().filename().string();
            ifstream file(entry.path().string());
            string content((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            doc.emplace_back(fileName, content);
        }
    }
    return vector<pair<string, string>>();
}

DocumentReader::~DocumentReader()
{
}