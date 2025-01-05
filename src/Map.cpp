#include "Map.h"

int Map::hashFunction(const string &key)
{
    size_t hash = 0;
    size_t prime = 31;
    for (char c : key)
    {
        hash = (hash * prime + c) % table.size();
    }
    return hash;
}
void Map::rehash()
{
    int newSize = table.size() * 2; // اندازه جدید
    vector<list<pair<string, vector<string>>>> newTable(newSize);

    for (const auto &bucket : table)
    {
        for (const auto &pair : bucket)
        {
            int newHashIndex = hashFunction(pair.first) % newSize;
            newTable[newHashIndex].emplace_back(pair);
        }
    }

    table = std::move(newTable); // جایگزینی جدول قدیمی با جدید
}
vector<string> Map::get(const string &key)
{
    int hashIndex = hashFunction(key);
    for (auto &pair : table[hashIndex])
    {
        if (pair.first == key)
        {
            return pair.second;
        }
    }
    return {};
}
void Map::insert(const string &key, const string &value)
{
    int hashIndex = hashFunction(key);

    for (auto &pair : table[hashIndex])
    {
        if (pair.first == key)
        {
            if (find(pair.second.begin(), pair.second.end(), value) == pair.second.end())
            {
                pair.second.push_back(value);
            }
            return;
        }
    }

    table[hashIndex].emplace_back(key, vector<string>{value});
    currentSize++;

    if (currentSize > table.size() * 0.75)
    {
        rehash();
    }
}