#include "../Helpers.hpp"

// Given an integer n, return true if it is a power of three. Otherwise, return false.
// An integer n is a power of three, if there exists an integer x such that n == 3x.

// Example 1:
// Input: n = 27
// Output: true

// Example 2:
// Input: n = 0
// Output: false

// Example 3:
// Input: n = 9
// Output: true

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        return n > 0 && 1'162'261'467 % n == 0; // 3^19
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}