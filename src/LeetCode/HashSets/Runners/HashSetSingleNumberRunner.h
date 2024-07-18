#pragma once

#include <iostream>
#include <chrono>
#include <numeric>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "LeetCode/HashSets/HashSetSingleNumber.h"

namespace LeetCode::HashSet
{
    class HashSetSingleNumberRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<HashSetSingleNumber> us = std::make_unique<HashSetSingleNumber>();

            int size = 2000001;
            int middle = 1000000;
            int number = 0;

            std::vector<int> v;
            v.reserve(size);
            for (int i = 0; i < 1000000; i+=2, ++number) {
                v.push_back(number);
                v.push_back(number);
            }
            v.push_back(2222221);

            for (int i = middle + 1; i < size; i += 2, ++number) {
                v.push_back(number);
                v.push_back(number);
            }

            std::cout << "Single number: " << us->singleNumber(v) << "\n";
        }
    };

    REGISTER_SOLUTION_RUNNER("HashSetSingleNumber", HashSetSingleNumberRunner)
}
