// The solution for a LeetCode lesson:
// https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1112/

#include <vector>
#include <unordered_set>

namespace LeetCode::HashSet
{
    class HashSetContainsDuplicate {
    public:
        bool containsDuplicate(std::vector<int>& nums) {
            std::unordered_set<int> hashSet(nums.size());
            for (const auto& n : nums) {
                if (!hashSet.insert(n).second) {
                    return true;
                }
            }

            return false;
        }
    };
}
