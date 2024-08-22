// The solution for a LeetCode problem:
// https://leetcode.com/problems/binary-search/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem704
{
    class BinarySearch
    {
    public:
        int search(std::vector<int>& nums, int target)
        {
            int left = 0;
            int right = nums.size() - 1;
            int middle = left + right / 2;

            while (left <= right)
            {
                if (nums[middle] == target) {
                    return middle;
                }
                else if (nums[middle] > target) {
                    right = middle - 1;
                }
                else {
                    left = middle + 1;
                }

                middle = (left + right) / 2;
            }

            return -1;
        }
    };

    struct TestCaseInfo
    {
        std::vector<int> nums;
        int target;
    };

    class BinarySearchRunner : public ISolutionRunner
    {
        using NumsVector = std::vector<int>;

    public:
        void run() override
        {
            std::unique_ptr<BinarySearch> solution = std::make_unique<BinarySearch>();

            std::vector<TestCaseInfo> testCases = {
                { { -1, 0, 3, 5, 9, 12 }, 9 },
                { { -1, 0, 3, 5, 9, 12 }, 2 },
                { { 2, 5 }, 0 }
            };

            for (auto& numsInfo : testCases) {
                // printing
                std::cout << "\n" << "Nums: ";
                for (const auto& n : numsInfo.nums) {
                        std::cout << n << " ";
                }

                // calculating
                std::cout << "\n" << "Target '" << numsInfo.target << "': " <<
                    (solution->search(numsInfo.nums, numsInfo.target) != -1 ? "found" : "not found") << "\n";
            }
        }
    };

    REGISTER_SOLUTION_RUNNER("BinarySearch", BinarySearchRunner)
}
