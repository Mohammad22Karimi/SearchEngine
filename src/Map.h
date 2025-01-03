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
    Map() : table(SIZE) {}
    void insert(const string &key, const string &value);
    string get(const string &key);
    ~Map();

private:
    static const int SIZE = 100;
    vector<list<pair<string, string>>> table;

    int hashFunction(const string &key);
};

#endif