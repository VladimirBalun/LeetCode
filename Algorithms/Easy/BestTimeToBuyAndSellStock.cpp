#include "../Helpers.hpp"

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
