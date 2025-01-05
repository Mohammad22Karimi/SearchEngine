#ifndef MAP_H
#define MAP_H

#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

class Map
{
public:
    Map() : table(SIZE), currentSize(0) {}
    void insert(const string &key, const string &value);
    vector<string> get(const string &key);
    // vector<string> keys(); // اعلام تابع keys
    void rehash();

private:
    static const int SIZE = 100;
    vector<list<pair<string, vector<string>>>> table;
    // int findKey(const string &key);
    int hashFunction(const string &key);
    int currentSize;
};

#endif