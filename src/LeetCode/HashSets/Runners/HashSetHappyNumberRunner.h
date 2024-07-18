#pragma once

#include <iostream>
#include <chrono>
#include <numeric>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "LeetCode/HashSets/HashSetHappyNumber.h"

namespace LeetCode::HashSet
{
    class HashSetHappyNumberRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            // Interesting moment: LeetCode showed my algorithm as it beating 100% other submissions in speed section.
            // And if we look at another top solution and load it under my test it would be 8.9 seconds average time
            // versus my algorithm with 2.65 seconds average time. Reason: poor tests on LeetCode.
            std::unique_ptr<HashSetHappyNumber> hs = std::make_unique<HashSetHappyNumber>();

            std::cout << "Started..." << "\n";

            auto start = std::chrono::high_resolution_clock::now();
            
            int size = 1000000;
            
            for (int i = 0; i < size; ++i)
            {
                hs->isHappy(i);
                std::cout << i << ": " << std::boolalpha << hs->isHappy(i) << std::endl;
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Time: " << duration.count() << " seconds" << std::endl;
        }
    };

    REGISTER_SOLUTION_RUNNER("HashSetHappyNumber", HashSetHappyNumberRunner)
}
