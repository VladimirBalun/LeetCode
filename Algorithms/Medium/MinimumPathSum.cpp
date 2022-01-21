#include "../Helpers.hpp"

// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
// Note: You can only move either down or right at any point in time.

// Example 1:
// Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
// Output: 7
// Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

// Example 2:
// Input: grid = [[1,2,3],[4,5,6]]
// Output: 12

class Solution
{
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        for (size_t i = 0u; i < grid.size(); ++i) {
            for (size_t j = 0u; j < grid[i].size(); ++j) {
                if (i == 0 && j > 0) {
                    grid[i][j] += grid[i][j - 1];
                } else if (i > 0 && j == 0) {
                    grid[i][j] += grid[i - 1][j];
                } else if (i > 0 && j > 0) {
                    grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
                }
            }
        }   
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
