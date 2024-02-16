#include "../Helpers.hpp"

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
// You may assume that you have an infinite number of each kind of coin.

// Example 1:
// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

// Example 2:
// Input: coins = [2], amount = 3
// Output: -1

// Example 3:
// Input: coins = [1], amount = 0
// Output: 0

class Solution
{
public:
    std::vector<int> closestPrimes(int left, int right)
    {
        int previous_prime = -1;
        int minimum_sum = std::numeric_limits<int>::max();

        std::vector<int> result{ -1, -1 };
        std::vector<bool> prime_numbers(right + 1, true);
        for (int i = 2; i <= right; i++) {
            if (!prime_numbers[i])
                continue;

            if (i >= left) {
                if (previous_prime != -1) {
                    int current_sum = i - previous_prime;
                    if (current_sum < minimum_sum) {
                        minimum_sum = current_sum;
                        result[0] = previous_prime;
                        result[1] = i;
                    }
                }

                previous_prime = i;
            }

            for (long j = (long)i*i; j <= right; j += i)
                prime_numbers[j] = false;
        }

        return result;
    }
};