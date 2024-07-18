// The solution for a LeetCode lesson:
// https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1176/

#include <vector>
#include <unordered_set>

namespace LeetCode::HashSet
{
    class HashSetSingleNumber {
    public:
        int singleNumber(std::vector<int>& nums) {
            int result = 0;

            for (const int& n : nums) {
                result ^= n;
            }

            return result;
        }
    };
}
