// The solution for a LeetCode problem:
// https://leetcode.com/problems/climbing-stairs/description/

#include <vector>
#include <unordered_map>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem70
{
    class ClimbingStairs
    {
    public:
        int climbStairs(int n)
        {
            std::unordered_map<int, int> stepsNums;

            return climb(n, stepsNums);
        }

        int climb(int stepsLeft, std::unordered_map<int, int>& stepsNums)
        {
            if (stepsLeft == 0) {
                return 1;
            }
            else if (stepsLeft < 0) {
                return 0;
            }

            if (stepsNums.count(stepsLeft) > 0) {
                return stepsNums.at(stepsLeft);
            }

            stepsNums[stepsLeft] = climb(stepsLeft - 1, stepsNums) + climb(stepsLeft - 2, stepsNums);
            return stepsNums[stepsLeft];
        }
    };

    class ClimbingStairsRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<ClimbingStairs> solution = std::make_unique<ClimbingStairs>();

            std::vector<int> stepsNumbers = { 2, 3, 5, 10, 45 };

            std::cout << "\n";

            for (auto stepsNumber : stepsNumbers) {
                std::cout << "For \"" << stepsNumber << "\" steps there would be \"" << solution->climbStairs(stepsNumber) << "\"\n";
            }

            std::cout << "\n";
        }
    };

    REGISTER_SOLUTION_RUNNER("ClimbingStairs", ClimbingStairsRunner)
}
