#pragma once

#include <iostream>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"
#include "LeetCode/HashSets/IHashSet.h"
#include "LeetCode/HashSets/HashSetGrowing.h"

namespace LeetCode::HashSet
{
    class HashSetGrowingRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<IHashSet> hs = std::make_unique<HashSetGrowing>();

            auto printContains = [&hs](const int value) {
                std::cout << "\n" << "Table contains(" << value << ") = " << std::boolalpha << hs->contains(value) << "\n";
            };

            std::cout << "Running HashSetGrowing" << "\n";

            for (const int num : {2, 5, 6, 10, 12, 15, 15, 25, 25}) {
                hs->add(num);
                hs->print();
            }

            printContains(15);
            printContains(16);
            hs->remove(15);
            hs->print();
            hs->remove(16);
            hs->print();
            hs->remove(27);
            hs->print();
            hs->add(27);
            hs->print();
            hs->remove(27);
            hs->print();
            printContains(27);
            hs->add(513);
            hs->add(5);
        }
    };

    REGISTER_SOLUTION_RUNNER("HashSetGrowing", HashSetGrowingRunner)
}