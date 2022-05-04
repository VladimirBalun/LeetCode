#include "../Helpers.hpp"

// You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
// Given the integer n, return the number of complete rows of the staircase you will build.

// Example 1:
// Input: n = 5
// Output: 2
// Explanation: Because the 3rd row is incomplete, we return 2.

// Example 2:
// Input: n = 8
// Output: 3
// Explanation: Because the 4th row is incomplete, we return 3.

class Solution
{
public:
    int arrangeCoins(int n)
    {
        int left = 1;
        int right = n;

        while (left <= right) {
            const long middle = left + (right - left) / 2;
            if (middle * (middle + 1) <= n * 2l) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return right;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
