#pragma once

#include <iostream>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "Templates/HashMaps/IHashMap.h"
#include "Templates/HashMaps/HashMap.h"

namespace Template::HashMap
{
    class HashMapRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<IHashMap<std::string, int>> ht = std::make_unique<HashMap<std::string, int>>(5);

            std::cout << "Running HashTableT" << "\n";

            auto printGet = [&ht](const std::string key) {
                auto res = ht->get(key);
                std::cout << "\n" << "Table contains(" << key << ") = " << (res.has_value() ? std::to_string(res.value()) : "-") << "\n";
            };

            printGet("Alex");
            ht->remove("Alex");
            ht->put("Alex", 37);
            ht->print();
            ht->put("Xena", 30);
            ht->print();
            ht->put("Alex", 36);
            ht->print();
            ht->put("Jack", 66);
            ht->print();
            ht->put("Niko", 11);
            ht->print();
            ht->put("Okin", 11);
            ht->print();
            ht->put("Teresa", 26);
            ht->print();
            ht->remove("Teresa");
            ht->print();
            ht->put("Teresa", 24);
            ht->print();
            ht->put("Teresa", 25);
            ht->print();
            ht->put("Markus", 10);
            ht->print();
            ht->remove("Markus");
            ht->print();
            ht->put("Markus", 10);
            ht->print();
            ht->put("Aurelius", 2500);
            ht->print();
            ht->put("Jack", 33);
            ht->print();
            ht->put("Notch", 41);
            ht->print();
            ht->put("Drone", 0);
            ht->print();
            printGet("Jack");
            ht->remove("Jack");
            ht->remove("Jack");
            printGet("Jack");
        }
    };

    REGISTER_SOLUTION_RUNNER("HashTableSimpleT", HashMapRunner)
}