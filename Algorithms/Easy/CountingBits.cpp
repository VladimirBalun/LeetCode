#include "../Helpers.hpp"

// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

// Example 1:
// Input: n = 2
// Output: [0,1,1]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10

// Example 2:
// Input: n = 5
// Output: [0,1,1,2,1,2]
// Explanation:
// 0 --> 0
// 1 --> 1
// 2 --> 10
// 3 --> 11
// 4 --> 100
// 5 --> 101

class Solution {
public:
    std::vector<int> countBits(int n)
    {
        size_t offset = 1u;
        std::vector<int> dp(n + 1, 0);
        for (size_t i = 1u; i < n + 1; ++i) {
            if (offset * 2 == i)
                offset = i;
            
            dp[i] = 1 + dp[i - offset];
        }
        
        return dp;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}