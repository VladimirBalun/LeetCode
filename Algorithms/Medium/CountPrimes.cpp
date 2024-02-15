#include "../Helpers.hpp"

// Given an integer n, return the number of prime numbers that are strictly less than n.

// Example 1:
// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

// Example 2:
// Input: n = 0
// Output: 0

// Example 3:
// Input: n = 1
// Output: 0

class Solution {
public:
    int countPrimes(int n) {
        int primes_number = 0;
        std::vector<bool> numbers(n, true);
        for (int i = 2; i < n; ++i) {
            if (!numbers[i])
                continue;

            ++primes_number;
            for (auto j = (long)i * i; j < n; j += i)
                numbers[j] = false;
        }

        return primes_number;
    }
};
