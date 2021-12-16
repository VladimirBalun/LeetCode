#include "../Helpers.hpp"

// You are given an array prices where prices[i] is the price of a given stock on the ith day.
// You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
// Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

// Example 1:
// Input: prices = [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

// Example 2:
// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transactions are done and the max profit = 0.

class Solution
{
public:
    int maxProfit(const std::vector<int>& prices)
    {
        int max_profit = 0;
        int min = std::numeric_limits<int>::max();
        for (const int price : prices) {
            if (price < min) {
                min = price;
            } else if (price - min > max_profit) {
                max_profit = price - min;
            }
        }

        return max_profit;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        const std::vector<int> data{ 7, 1, 5 };
        ASSERT_EQUALS(solution.maxProfit(data), 4);
    }
    {
        const std::vector<int> data{ 7, 1, 5, 3, 6, 4 };
        ASSERT_EQUALS(solution.maxProfit(data), 5);
    }
    {
        const std::vector<int> data{ 2, 4, 1 };
        ASSERT_EQUALS(solution.maxProfit(data), 2);
    }
    {
        const std::vector<int> data{ 7, 6, 4, 3, 1 };
        ASSERT_EQUALS(solution.maxProfit(data), 0);
    }
    return EXIT_SUCCESS;
}
