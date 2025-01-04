#include "Map.h"

Map::~Map()
{
}

int Map::hashFunction(const string &key)
{
    int hash = 0;
    for (char c : key)
    {
        hash = (hash * 31 + c) % SIZE;
    }
    return hash;
}

string Map::get(const string &key)
{
    int hashIndex = hashFunction(key);
    for (auto &pair : table[hashIndex])
    {
        if (pair.first == key)
        {
            return pair.second;
        }
    }
    return "key not found\n";
}
void Map::insert(const string &key, const string &value)
{
    int hashIndex = hashFunction(key);
    for (auto &pair : table[hashIndex])
    {
        if (pair.first == key)
        {
            pair.second = value;
            return;
        }
    }
    table[hashIndex].emplace_back(key, value);
}