// The solution for a LeetCode lesson:
// https://leetcode.com/explore/learn/card/hash-table/184/comparison-with-other-data-structures/1117/

#include <bitset>
#include <string>
#include <vector>
#include <unordered_map>

namespace LeetCode::HashMap
{
    class HashMapIsomorphicStrings
    {
    public:
        // strings are not passed by reference because thats how the function is declared on LeetCode
        bool isIsomorphic(std::string s, std::string t)
        {
            if (s.size() != t.size()) {
                 return false;
            }

            std::unordered_map<char, char> stMap;
            std::unordered_map<char, char> tsMap;

            for (int i = 0; i < s.size(); i++) {
                if (stMap.count(s[i]) > 0) {
                    if (stMap[s[i]] != t[i]) {
                        return false;
                    }
                }
                else if (tsMap.count(t[i]) > 0) {
                    if (tsMap[t[i]] != s[i]) {
                        return false;
                    }
                }
                else {
                    stMap[s[i]] = t[i];
                    tsMap[t[i]] = s[i];
                }
            }

            return true;
        }


        bool isIsomorphicInBits(std::string s, std::string t)
        {
            // a solution without hash map just to practice
            if (s.size() != t.size()) {
                return false;
            }

            // bitsets to detect if char already used
            std::bitset<256> sSet = 0;
            std::bitset<256> tSet = 0;
            // relation arrays
            char stChars[256] = {0};

            for (int i = 0; i < s.size(); i++) {
                auto sc = s[i];
                auto st = t[i];

                if (sSet[s[i]] == 0 && tSet[t[i]] == 0) {
                    stChars[s[i]] = t[i];

                    sSet[s[i]] = 1;
                    tSet[t[i]] = 1;
                }
                else if (stChars[s[i]] != t[i]) {
                    return false;
                }
            }

            return true;
        }
    };
}
