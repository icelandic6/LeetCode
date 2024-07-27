#pragma once

#include <iostream>
#include <chrono>
#include <numeric>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

#include "LeetCode/HashMaps/HashMapIsomorphicStrings.h"

namespace LeetCode::HashMap
{
    class HashMapIsomorphicStringsRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            using IsoStrings = std::pair<std::string, std::string>;

            std::unique_ptr<HashMapIsomorphicStrings> hm = std::make_unique<HashMapIsomorphicStrings>();

            std::vector<IsoStrings> isoTexts = {
                {"badc", "baba"},
                {"egg", "add"},
                {"foo", "bar"},
                {"paper", "title"},
                {"small", "big"},
                {"tt", "tt"},
                {"banana", "cododo"},
                {"banana", "bazana"},
            };

            for (const auto& textsPair : isoTexts) {
                bool result = hm->isIsomorphic(textsPair.first, textsPair.second);
                std::cout << "\"" << textsPair.first << "\" & \"" << textsPair.second << "\" = " << std::boolalpha << result << "\n";

            }

            std::cout << "\n\n";
        }
    };

    REGISTER_SOLUTION_RUNNER("HashMapIsomorphicStrings", HashMapIsomorphicStringsRunner)
}
