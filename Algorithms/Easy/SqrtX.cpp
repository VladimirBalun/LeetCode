#include "../Helpers.hpp"

// Given a non-negative integer x, compute and return the square root of x.
// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
// Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

// Example 1:
// Input: x = 4
// Output: 2

// Example 2:
// Input: x = 8
// Output: 2
// Explanation: The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 1)
            return 1;
        
        int left = 0;
        int right = x;
        
        while (right - left > 1) {
            const long long middle = left + (right - left) / 2;
            const long long target = middle * middle;
            if (target <= x) {
                left = middle;
            } else {
                right = middle;
            }
        }

        return left;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
