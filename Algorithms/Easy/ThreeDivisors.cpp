#include "../Helpers.hpp"

// Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.
// An integer m is a divisor of n if there exists an integer k such that n = k * m.

// Example 1:
// Input: n = 2
// Output: false
// Explantion: 2 has only two divisors: 1 and 2.

// Example 2:
// Input: n = 4
// Output: true
// Explantion: 4 has three divisors: 1, 2, and 4.

class Solution {
public:
    bool isThree(int n)
    {
        if (n < 4)
            return false;

        const int n_square = sqrt(n);
        return n_square * n_square == n && isPrime(n_square);
    }

    bool isPrime(int n)
    {
        const int n_square = sqrt(n);
        for (int i = 2; i <= n_square; ++i) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
};