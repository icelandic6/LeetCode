// The solution for a LeetCode lesson:
// https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1115/

#include <vector>
#include <unordered_map>

namespace LeetCode::HashMap
{
    class HashMapTwoSum
    {
    public:
        std::vector<int> twoSum(std::vector<int>& nums, int target)
        {
            std::unordered_map<int, int> checkedNums;

            for (auto i = 0; i < nums.size(); ++i) {
                int difference = target - nums[i];
                if (checkedNums.count(difference) > 0) {
                    return std::vector<int>{checkedNums[difference], i};
                }

                checkedNums[nums[i]] = i;
            }

            return std::vector<int>{};
        }
    };
}
