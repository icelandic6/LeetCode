// The solution for a LeetCode problem:
// https://leetcode.com/problems/missing-number

#include <vector>
#include <unordered_map>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem268
{
    // simple one
    class MissingNumberSimple
    {
    public:
        int missingNumber(std::vector<int>& nums)
        {
            int size = static_cast<int>(nums.size());
            std::unordered_map<int, bool> seenNums(size);

            for (const int num : nums) {
                seenNums[num] = true;
            }

            for (int i = 0; i < size; ++i) {
                if (!seenNums[i]) {
                    return i;
                }
            }

            return size;
        }
    };

    // more elegant
    class MissingNumber
    {
    public:
        int missingNumberThroughSums(std::vector<int>& nums)
        {
            int n = static_cast<int>(nums.size());
            int wholeSum = (n * (n + 1)) / 2;

            int difSum = 0;
            for (const int num : nums) {
                difSum += num;
            }

            return wholeSum - difSum;
        }
    };

    class MissingNumberRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<MissingNumber> solution = std::make_unique<MissingNumber>();

            using VectorIntegers = std::vector<int>;
            std::vector<VectorIntegers> allNumsVectors = {
                { 0, 1 },
                { 3, 0, 1 },
                { 9, 6, 4, 2, 3, 5, 7, 0, 1}
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
                std::cout << "Missing Number: " << solution->missingNumberThroughSums(nums) << "\n\n";
            }

            std::cout << "\n";
        }
    };

    REGISTER_SOLUTION_RUNNER("MissingNumber", MissingNumberRunner)
}
