#pragma once

#include <iostream>
#include <chrono>
#include <numeric>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "LeetCode/HashSets/HashSetContainsDuplicate.h"

namespace LeetCode::HashSet
{
    class HashSetContainsDuplicateRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<HashSetContainsDuplicate> us = std::make_unique<HashSetContainsDuplicate>();

            std::vector<int> v;
            for (int i = 0; i < 5000000; v.push_back(i), ++i);

            std::cout << "Started..." << "\n";
            std::vector<double> durations;
            for (int c = 0; c < 10; ++c)
            {
                auto start = std::chrono::high_resolution_clock::now();
                us->containsDuplicate(v);
                auto end = std::chrono::high_resolution_clock::now();

                std::chrono::duration<double> duration = end - start;
                if (c != 0) {
                    durations.push_back(duration.count());
                }

                std::cout << "Time: " << duration.count() << " seconds" << std::endl;
            }

            double sum = std::accumulate(durations.begin(), durations.end(), 0.0);
            std::cout << "Average time: " << sum / durations.size() << std::endl;
        }
    };

    REGISTER_SOLUTION_RUNNER("HashSetContainsDuplicate", HashSetContainsDuplicateRunner)
}
