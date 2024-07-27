// The solution for a LeetCode problem:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

#include <vector>
#include <unordered_map>

#include "Solutions/ISolutionRunner.h"
#include "Solutions/SolutionFactory.h"

namespace LeetCode::Problem121
{
    class BestTimeToBuyAndSellStockSimple
    {
    public:
        int maxProfit(std::vector<int>& prices)
        {
            if (prices.empty()) {
                return 0;
            }

            int bestPriceToBuy = prices[0];
            int maxProfit = 0;

            for (int i = 0; i < static_cast<int>(prices.size()); ++i) {
                if (prices[i] < bestPriceToBuy) {
                    bestPriceToBuy = prices[i];
                }

                maxProfit = std::max(maxProfit, prices[i] - bestPriceToBuy);
            }

            return maxProfit;
        }
    };

    class BestTimeToBuyAndSellStockRecursive
    {
    public:
        using Cache = std::unordered_map<int, int>;

        int run(const std::vector<int>& prices, int index, bool buyDone, Cache& cacheMaxSell)
        {
            if (index == static_cast<int>(prices.size())) {
                return 0;
            }

            if (buyDone && cacheMaxSell.count(index) > 0) {
                return cacheMaxSell[index];
            }

            if (buyDone) {
                int currentSellPrice = prices[index];
                int otherDaysMaxSellPrice = run(prices, index + 1, buyDone, cacheMaxSell);

                int maxProfit = std::max(currentSellPrice, otherDaysMaxSellPrice);

                cacheMaxSell[index] = maxProfit;
                return maxProfit;
            }

            int maxSellPriceIfBuyOnNextDay = run(prices, index + 1, true, cacheMaxSell);
            int maxSellPriceIfNotBuyOnNextDay = run(prices, index + 1, false, cacheMaxSell);

            int maxProfit = std::max(maxSellPriceIfBuyOnNextDay - prices[index], maxSellPriceIfNotBuyOnNextDay);
            return maxProfit;
        }
    };

    class BestTimeToBuyAndSellStockRunner : public ISolutionRunner
    {
    public:
        void run() override
        {
            std::unique_ptr<BestTimeToBuyAndSellStockSimple> solution = std::make_unique<BestTimeToBuyAndSellStockSimple>();

            std::vector<std::vector<int>> testNums = {
                {7, 1, 5, 3, 6, 4 },
                {7, 6, 4, 3, 1},
                { 2, 4, 1}
            };

            std::cout << "\n";

            auto printNums = [](const std::vector<int>& nums) {
                for (const auto& n : nums) {
                    std::cout << n << " ";
                }
                std::cout << "\n";
            };

            for (auto nums : testNums) {
                std::cout << "Nums: ";
                printNums(nums);
                std::cout << "Max profit: " << solution->maxProfit(nums) << "\n\n";
            }

            std::cout << "\n";
        }
    };

    REGISTER_SOLUTION_RUNNER("BestTimeToBuyAndSellStock", BestTimeToBuyAndSellStockRunner)
}
