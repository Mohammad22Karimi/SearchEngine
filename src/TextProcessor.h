#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#pragma once

#include <string>
#include <vector>
using namespace std;
class TextProcessor
{
public:
    TextProcessor();
    ~TextProcessor();

private:
    vector<string> clearnText(const string &text);
};

#endif