// The solution for a LeetCode lesson using a template growing HashSet:
// https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1139/

#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

#include "IHashSet.h"

namespace Template::HashSet
{
    template<typename T>
    class HashSetGrowing : public IHashSet<T>
    {
        using HashSet = std::vector<std::list<T>>;

    public:
        HashSetGrowing()
        {
            _table.resize(_maxTableSize);
        }

        void add(const T& key) override
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

        void remove(const T& key) override
        {
            const size_t index = hash(key);

            if (_table[index].empty()) {
                return;
            }

            const auto it = search(key);
            if (it != _table[index].end()) {
                _table[index].erase(it);
            }

            --_tableSize;
        }

        typename std::list<T>::iterator search(const T& key)
        {
            const size_t index = hash(key);
            return std::find(_table[index].begin(), _table[index].end(), key);
        }

        bool contains(const T& key) override
        {
            const size_t index = hash(key);
            return search(key) != _table[index].end();
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
                        chainLogText << elem << " ";
                    }
                    std::cout << chainLogText.str() << "\n";
                }
            }

            std::cout << "\n";
        }

    private:
        size_t hash(const T& value) const override
        {
            return static_cast<size_t>(std::hash<T>{}(value)) % _maxTableSize;
        }

        void growAndRehashTable()
        {
            _maxTableSize = _table.size() * static_cast<size_t>(_growFactor);

            HashSet newTable(_maxTableSize);

            for (const auto& chain : _table)
            {
                for (const auto& key : chain)
                {
                    size_t newIndex = hash(key);
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
