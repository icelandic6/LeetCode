// The solution for a LeetCode lesson using a template HashMap:
// https://leetcode.com/explore/learn/card/hash-table/182/practical-applications/1140/
#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include <list>

#include "IHashMap.h"

namespace Template::HashMap
{
    template<typename T, typename V>
    class HashMap final : public IHashMap<T, V>
    {
        using HashTable = std::vector<std::list<std::pair<T, V>>>;
        using List = std::list<std::pair<T, V>>;

    public:
        HashMap(int size)
            : _hashValue(size)
            , _table(size)
        {
        }

        void put(const T& key, const V& value) override
        {
            const auto index = hash(key);
            const auto it = search(key);

            if (it != _table[index].end()) {
                it->second = value;
            }
            else {
                _table[index].emplace_back(key, value);
            }
        }

        void remove(const T& key) override
        {
            const auto index = hash(key);
            if (_table[index].empty()) {
                return;
            }

            const auto it = search(key);
            if (it != _table[index].end()) {
                _table[index].erase(it);
            }
        }

        std::optional<V> get(const T& key) override
        {
            const auto index = hash(key);

            const auto it = search(key);
            if (it != _table[index].end()) {
                return it->second;
            }

            return std::nullopt;
        }

        typename List::iterator search(const T& key)
        {
            const auto index = hash(key);
            return std::find_if(_table[index].begin(), _table[index].end(), [key](const std::pair<T, V>& p) {
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
        size_t hash(const T& value) const override
        {
            // custom hasher could have been written here, but it won't be rn
            std::hash<T> hasher;
            return hasher(value) % _hashValue;
        }

    private:
        int _hashValue;
        HashTable _table;
    };
}
