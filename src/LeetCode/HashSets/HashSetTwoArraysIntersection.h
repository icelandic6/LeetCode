// The solution for a LeetCode lesson:
// https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1105/

#include <vector>
#include <unordered_set>

namespace LeetCode::HashSet
{
    class HashSetTwoArraysIntersection {
    public:
        std::vector<int> intersection(std::vector<int>&nums1, std::vector<int>&nums2) {
            if (nums1.size() == 0 || nums2.size() == 0) {
                return {};
            }

            std::unordered_set<int> set1(nums1.begin(), nums1.end());
            std::unordered_set<int> set2(nums2.begin(), nums2.end());

            std::vector<int> resultVector;
            resultVector.reserve(nums1.size() > nums2.size() ? nums1.size() : nums2.size());
            for (int n : set1) {
                if (set2.count(n) > 0) {
                    resultVector.push_back(n);
                }
            }
            
            return resultVector;
        }
    };
}
