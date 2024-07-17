#pragma once

#include <iostream>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "LeetCode/HashMaps/IHashMap.h"
#include "LeetCode/HashMaps/HashMap.h"

namespace LeetCode::HashMap
{
    class HashMapRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<IHashMap> ht = std::make_unique<HashMap>(4, 2);

            auto printGet = [&ht](const int value){
                std::cout << "\n" << "Table contains(" << value << ") = " << std::boolalpha << ht->get(value) << "\n";
            };

            std::cout << "Running HashMap" << "\n";
            ht->print();

            for (const auto& p : std::initializer_list<std::pair<int, int>>{
                {2, 2}, {2, 3}, {3, 2}, {3, 3}, {2, 12}, {2, 22}, {2, 32}, {12, 22}, {22, 22}, {22, 32}, {22, 44}}) {
                ht->put(p.first, p.second);
                ht->print();
            }

            for (const auto n : { 2, 12, 12, 66 }) {
                ht->remove(n);
                ht->print();
            }

            for (const auto n : { 1, 2, 12, 22, 32, 33, 44 }) {
                printGet(n);
            }
        }
    };

    REGISTER_SOLUTION_RUNNER("HashMap", HashMapRunner)
}
