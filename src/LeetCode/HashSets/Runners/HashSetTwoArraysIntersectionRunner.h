#pragma once

#include <iostream>
#include <chrono>
#include <numeric>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "LeetCode/HashSets/HashSetTwoArraysIntersection.h"

namespace LeetCode::HashSet
{
    class HashSetTwoArraysIntersectionRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<HashSetTwoArraysIntersection> hs = std::make_unique<HashSetTwoArraysIntersection>();

            int size = 100;
            std::vector<int> nums1;
            nums1.reserve(size / 2);
            std::vector<int> nums2;
            nums2.reserve(size);

            for (int i = 0; i < size; ++i) {
                if (i % 2 == 0) {
                    nums1.push_back(i);
                }
                nums2.push_back(i);
            }

            auto printVector = [](const std::string& prefixText, const std::vector<int>& vec) {
                std::cout << prefixText << "\t";
                std::ostringstream oss;
                for (const int& value : vec) {
                    oss << value << " ";
                }
                std::cout << oss.str() << "\n";
            };

            printVector("First vector:", nums1);
            printVector("Second vector:", nums2);
            printVector("Intersection:", hs->intersection(nums1, nums2));
        }
    };

    REGISTER_SOLUTION_RUNNER("HashSetTwoArraysIntersection", HashSetTwoArraysIntersectionRunner)
}
