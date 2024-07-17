// The solution for a LeetCode lesson using a template simple HashSet of static size:
// https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1139/

#pragma once

#include <iostream>
#include <sstream>

#include "IHashSet.h"

namespace Template::HashSet
{
    template<typename T>
    class HashSetSimple final : public IHashSet<T>
    {
    public:
        using HashSet = std::vector<std::list<T>>;

        HashSetSimple()
        {
            _table.resize(_tableSize);
        }

        void add(const T& key) override
        {
            std::cout << "Adding \"" << key << "\"" << "\n";
            const size_t index = hash(key);

            if (!contains(key)) {
                _table[index].emplace_back(key);
            }
        }

        void remove(const T& key) override
        {
            std::cout << "Removing \"" << key << "\"" << "\n";

            const size_t index = hash(key);
            _table[index].remove(key);
        }

        bool contains(const T& key) override
        {
            const size_t index = hash(key);
            return std::find(_table[index].begin(), _table[index].end(), key) != _table[index].end();
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
        size_t hash(const T& value) const override
        {
            return static_cast<size_t>(value % _tableSize);
        }

    private:
        int _tableSize = 5;

        HashSet _table;
    };
}