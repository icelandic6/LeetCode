// The solution for a LeetCode lesson using a growing HashSet:
// https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1139/

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

#include "IHashSet.h"

namespace LeetCode::HashSet
{
    class HashSetGrowing final : public IHashSet
    {
        using HashSet = std::vector<std::list<int>>;

    public:
        HashSetGrowing()
        {
            _table.resize(_maxTableSize);
        }

        void add(int key) override
        {
            if (contains(key)) {
                return;
            }

            if (_tableSize >= _maxTableSize) {
                growAndRehashTable();
            }

            const size_t index = hash(key);
            _table[index].push_back(key);
            ++_tableSize;
        }

        void remove(int key) override
        {
            const size_t index = hash(key);

            if (_table[index].empty())
                return;

            const auto it = search(key);
            if (it != _table[index].end()) {
                _table[index].erase(it);
            }

            --_tableSize;
        }

        std::list<int>::iterator search(int key)
        {
            const size_t index = hash(key);
            return std::find(_table[index].begin(), _table[index].end(), key);
        }

        bool contains(int key) override
        {
            const size_t index = hash(key);
            return search(key) != _table[index].end();
        }

        void print() const override
        {
            std::cout << "Table:" << "\n";

            for (const auto& chain : _table) {
                if (chain.empty()) {
                    std::cout << "-" << "\n";
                }
                else {
                    std::ostringstream chainLogText;
                    for (const auto& elem : chain) {
                        chainLogText << elem << " ";
                    }
                    std::cout << chainLogText.str() << "\n";
                }
            }

            std::cout << "\n";
        }

    private:
        size_t hash(int value) const override
        {
            return static_cast<size_t>(value) % _maxTableSize;
        }

        void growAndRehashTable()
        {
            _maxTableSize = _table.size() * static_cast<size_t>(_growFactor);
            HashSet newTable(_maxTableSize);

            for (const auto& chain : _table)
            {
                for (const auto& key : chain)
                {
                    const int newIndex = hash(key);
                    newTable[newIndex].push_back(key);
                }
            }

            _table = std::move(newTable);
        }

    private:
        size_t _maxTableSize = 5;
        size_t _tableSize = 0;
        int _growFactor = 2;

        HashSet _table;
    };
}
