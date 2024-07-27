// The solution for a LeetCode problem:
// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/

#include <vector>
#include <unordered_set>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem448
{
    class FindAllNumbersDisappeared
    {
    public:
        std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
        {
            std::unordered_set<int> seenNums(nums.begin(), nums.end());
            std::vector<int> missedNums;
            missedNums.reserve(nums.size() - seenNums.size());

            for (int i = 1; i <= nums.size(); ++i) {
                if (seenNums.count(i) == 0) {
                    missedNums.emplace_back(i);
                }
            }

            return missedNums;
        }
    };

    class FindAllNumbersDisappearedRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<FindAllNumbersDisappeared> solution = std::make_unique<FindAllNumbersDisappeared>();

            using VectorIntegers = std::vector<int>;
            std::vector<VectorIntegers> allNumsVectors = {
                { 4, 3, 2, 7, 8, 2, 3, 1 },
                { 1, 1 },
            };

            auto printNums = [](const VectorIntegers& nums) {
                for (const auto& n : nums) {
                    std::cout << n << " ";
                }
                std::cout << "\n";
            };

            std::cout << "\n";

            for (auto& nums : allNumsVectors) {
                std::cout << "Nums: ";
                printNums(nums);
                std::cout << "Disappeared Numbers: ";
                printNums(solution->findDisappearedNumbers(nums));
            }

            std::cout << "\n";
        }
    };

    REGISTER_SOLUTION_RUNNER("FindAllNumbersDisappeared", FindAllNumbersDisappearedRunner)
}
