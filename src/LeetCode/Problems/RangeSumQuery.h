// The solution for a LeetCode problem:
// https://leetcode.com/problems/range-sum-query-immutable/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem121
{
    class NumArray
    {
    public:
        NumArray(std::vector<int>& nums)
            : _nums(nums.size())
        {
            _nums[0] = nums[0];

            for (int i = 1; i < static_cast<int>(nums.size()); ++i) {
                _nums[i] = _nums[i - 1] + nums[i];
            }
        }

        int sumRange(int left, int right) {
            if (left - 1 < 0) {
                return _nums[right];
            }

            int result = _nums[right] - _nums[left - 1];

            return result;
        }

    private:
        std::vector<int> _nums;
    };

    class RangeSumQueryRunner : public ISolutionRunner
    {

    public:
        void run() override
        {
            std::vector<int> nums = { -2, 0, 3, -5, 2, -1 };
            std::vector<std::pair<int, int>> ranges = {
                {0, 2},
                {2, 5},
                {0, 5},
                {1, 4},
                {0, 1},
                {3, 4}
            };

            std::unique_ptr<NumArray> solution = std::make_unique<NumArray>(nums);

            std::cout << "\n";

            auto printNums = [](const std::vector<int>& nums) {
                for (const auto& n : nums) {
                    std::cout << n << " ";
                }
                std::cout << "\n";
            };

            std::cout << "Nums: ";
            printNums(nums);
            for (auto& range : ranges) {
                std::cout << "Range(" << range.first << ", " << range.second << "): " << solution->sumRange(range.first, range.second) << "\n\n";
            }

            std::cout << "\n";
        }
    };

    REGISTER_SOLUTION_RUNNER("RangeSumQuery", RangeSumQueryRunner)
}
