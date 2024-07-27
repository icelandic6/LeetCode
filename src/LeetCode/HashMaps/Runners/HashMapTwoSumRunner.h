#pragma once

#include <iostream>
#include <chrono>
#include <numeric>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "LeetCode/HashMaps/HashMapTwoSum.h"

namespace LeetCode::HashMap
{
    class HashMapTwoSumRunner : public ISolutionRunner
    {
        using NumsAndTarget = std::pair<std::vector<int>, int>;

    public:
        void run() override
        {
            auto printVector = [](const std::vector<int> v)
                {
                    for (const auto n : v) {
                        std::cout << n << " ";
                    }
                };

            std::unique_ptr<HashMapTwoSum> hm = std::make_unique<HashMapTwoSum>();

            std::vector<NumsAndTarget> numsVector = {
                { {2, 7, 11, 15}, 9},
                { {3, 2, 4}, 6 },
                { {3, 3}, 6},
                { {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}, 38 }
            };

            std::cout << "\n";

            for (auto& numsAndTarget : numsVector) {
                std::cout << "Initial Vector: ";
                printVector(numsAndTarget.first);
                std::cout << "\n";

                std::cout << "Result  Vector: ";
                printVector(hm->twoSum(numsAndTarget.first, numsAndTarget.second));
                std::cout << "\n\n";
            }
        }
    };

    REGISTER_SOLUTION_RUNNER("HashMapTwoSum", HashMapTwoSumRunner)
}
