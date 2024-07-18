// The solution for a LeetCode lesson:
// https://leetcode.com/explore/learn/card/hash-table/183/combination-with-other-algorithms/1131/

#include <vector>
#include <unordered_set>

namespace LeetCode::HashSet
{
    class HashSetHappyNumber {
    public:
        bool isHappy(int n) {
            if (n <= 0) {
                return false;
            }

            if (n == 1 || n == 7) {
                return true;
            }

            std::unordered_set<int> repeatedNumbers;
            static std::unordered_set<int> happyNumbers = {1, 7};
            static std::unordered_set<int> unhappyNumbers;
            repeatedNumbers.reserve(10);

            int currentNumber = n;
            int sumNumber = 0;

            while (true) {
                sumNumber = 0;
                while (currentNumber > 0) {
                    sumNumber += (currentNumber % 10) * (currentNumber % 10);
                    currentNumber /= 10;
                }

                currentNumber = sumNumber;

                if (currentNumber == 1) {
                    break;
                }

                if (happyNumbers.count(currentNumber) > 0) {
                    return true;
                }

                if (unhappyNumbers.count(currentNumber) > 0) {
                    unhappyNumbers.insert(repeatedNumbers.begin(), repeatedNumbers.end());
                    return false;
                }

                if (repeatedNumbers.count(currentNumber) > 0) {
                    unhappyNumbers.insert(repeatedNumbers.begin(), repeatedNumbers.end());
                    unhappyNumbers.insert(currentNumber);
                    return false;
                }

                repeatedNumbers.insert(currentNumber);
            }

            if (currentNumber == 1) {
                happyNumbers.insert(n);
                return true;
            };

            return false;
        }
    };
}
