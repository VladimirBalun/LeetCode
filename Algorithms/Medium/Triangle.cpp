#include "../Helpers.hpp"

// Given a triangle array, return the minimum path sum from top to bottom.
// For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

// Example 1:
// Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
// Output: 11
// Explanation: The triangle looks like:
//    2
//   3 4
//  6 5 7
// 4 1 8 3
// The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

// Example 2:
// Input: triangle = [[-10]]
// Output: -10

class Solution
{
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        const size_t size = triangle.size();
        std::vector<int> dp(size + 1);

        for (int i = size - 1; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = std::min(dp[j], dp[j + 1]) + triangle[i][j];
            }
        }

        return dp[0];
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
