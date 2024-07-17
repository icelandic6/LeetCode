// The solution for a LeetCode lesson using a HashMap:
// https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1140/

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

#include "IHashTable.h"

namespace LeetCode::HashTable
{
    class HashTableSimple final : public IHashTable
    {
        using Table = std::vector<std::list<std::pair<int, int>>>;

    public:
        HashTableSimple(int tableSize, int hashValue)
            : _hashValue(hashValue)
            , _table(tableSize)
        {
        }

        void put(int key, int value) override
        {
            const size_t index = hash(key);
            const auto it = search(key);

            if (it != _table[index].end()) {
                it->second = value;
            }
            else {
                _table[index].emplace_back(key, value);
            }
        }

        void remove(int key) override
        {
            const size_t index = hash(key);
            if (_table[index].empty()) {
                return;
            }

            const auto it = search(key);
            if (it != _table[index].end()) {
                _table[index].erase(it);
            }
        }

        int get(int key) override
        {
            const size_t index = hash(key);

            const auto it = search(key);
            if (it != _table[index].end()) {
                return it->second;
            }

            return -1;
        }

        std::list<std::pair<int, int>>::iterator search(int key)
        {
            const size_t index = hash(key);
            return std::find_if(_table[index].begin(), _table[index].end(), [key](const std::pair<int, int>& p) {
                return p.first == key;
                });
        }

        void print() const override
        {
            std::cout << "Table:" << "\n";

            for (const auto& chain : _table)
            {
                if (chain.empty()) {
                    std::cout << "-" << "\n";
                }
                else {
                    std::ostringstream chainLogText;
                    for (const auto& elem : chain) {
                        chainLogText << elem.first << " " << elem.second << " | ";
                    }
                    std::cout << chainLogText.str() << "\n";
                }
            }

            std::cout << "\n";
        }

    private:
        size_t hash(int value) const override
        {
            return static_cast<size_t>(value % _hashValue);
        }

    private:
        int _hashValue = 10;
        Table _table;
    };
}
