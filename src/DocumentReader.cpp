#include "DocumentReader.h"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

vector<pair<string, string>> DocumentReader::readDocument(const string &filePath)
{
    vector<pair<string, string>> doc;

    for (const auto &entry : fs::directory_iterator(filePath))
    {
        if (entry.is_regular_file())
        {
            string filePath = entry.path().string();
            string fileName = entry.path().filename().string();

            // InvertedIndex index;
            // index.addDocument(filePath);

            // ذخیره نام فایل فقط (بدون ذخیره محتوا)
            doc.emplace_back(fileName, filePath);
        }
    }

    return doc;
}
