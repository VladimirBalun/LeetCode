#include "../Helpers.hpp"

// Given a positive integer num, write a function which returns True if num is a perfect square else False.
// Follow up: Do not use any built-in library function such as sqrt.

// Example 1:
// Input: num = 16
// Output: true

// Example 2:
// Input: num = 14
// Output: false

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 1;
        int right = num;

        while (left <= right) {
            const long long middle = left + (right - left) / 2;
            const long long target = middle * middle;
            if (target < num) {
                left = middle + 1;
            } else if (target > num) {
                right = middle - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
