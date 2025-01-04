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
    InvertedIndex data;

    for (const auto &entry : fs::directory_iterator(filePath))
    {
        if (entry.is_regular_file() && entry.path().extension() == ".txt")
        {
            string filePath = entry.path().string();
            string fileName = entry.path().filename().string();

            data.addDocument(filePath);

            // ذخیره نام فایل فقط (بدون ذخیره محتوا)
            doc.emplace_back(fileName, "");
        }
    }

    return doc;
}

DocumentReader::~DocumentReader()
{
}