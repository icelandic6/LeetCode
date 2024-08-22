// The solution for a LeetCode problem:
// https://leetcode.com/problems/counting-bits/

#include <vector>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem338
{
    class CountingBits
    {
    public:
        std::vector<int> countBits(int n)
        {
            std::vector<int> answer(n + 1, 0);

            for (int i = 0; i <= n; ++i) {
                answer[i] = answer[i >> 1] + (i & 1);
            }

            return answer;
        }
    };

    class CountingBitsSimple
    {
    public:
        std::vector<int> countBits(int n)
        {
            std::vector<int> result(n + 1);

            for (int index = 0; index <= n; index++) {
                countOnes(index, result);
            }

            return result;
        }

        std::vector<int>& countOnes(int index, std::vector<int>& result)
        {
            if (index == 0) {
                return result;
            }

            int i = index;
            while (i > 0) {
                result[index] += i & 1;
                i = i / 2;
            }

            return result;
        }
    };

    class CountingBitsRunner : public ISolutionRunner
    {

    public:
        void run() override
        {
            std::cout << "Do you want to run normal tests (1) or load tests (2)?" << "\n";
            std::string userAnswer;
            std::getline(std::cin, userAnswer);
            if (userAnswer == "2") {
                runLoadTests();
            }
            else {
                runNormalTests();
            }
        }

        void runNormalTests()
        {
            std::unique_ptr<CountingBitsSimple> solution = std::make_unique<CountingBitsSimple>();

            std::vector<int> nums = { 2, 5, 10 };

            std::cout << "\n";

            auto printVector = [](const std::vector<int>& nums) {
                for (const auto& n : nums) {
                    std::cout << n << " ";
                }
                std::cout << "\n";
                };

            for (const auto n : nums) {
                std::cout << "N = " << n << "\n";
                std::cout << "Counted Bits = ";
                printVector(solution->countBits(n));
                std::cout << "\n";
            }
        }

        void runLoadTests()
        {
            // The execution time of load tests for the simple algorithm is ~66 seconds
            // The execution time of load tests for the bits algorithm is ~7 seconds
            std::unique_ptr<CountingBits> solution = std::make_unique<CountingBits>();

            int inputNumsLength = 50000;
            auto start = std::chrono::high_resolution_clock::now();

            auto printVector = [](const std::vector<int>& nums) {
                for (const auto& n : nums) {
                    std::cout << n << " ";
                }
                std::cout << "\n";
            };

            for (int n = 0; n < inputNumsLength; ++n) {
                solution->countBits(n);
            }

            auto end = std::chrono::high_resolution_clock::now();
            std::chrono::duration<double> duration = end - start;
            std::cout << "Time: " << duration.count() << " seconds" << "\n";
        }
    };

    REGISTER_SOLUTION_RUNNER("CountingBits", CountingBitsRunner)
}
