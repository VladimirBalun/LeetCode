#include "../Helpers.hpp"

// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
// The area of an island is the number of cells with a value 1 in the island.
// Return the maximum area of an island in grid. If there is no island, return 0.

// Example 1:
// Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
// Output: 6
// Explanation: The answer is not 11, because the island must be connected 4-directionally.

// Example 2:
// Input: grid = [[0,0,0,0,0,0,0,0]]
// Output: 0

class Solution
{
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid)
    {
        std::function<int(int, int)> dfs;
        dfs = [&dfs, &grid] (int i, int j)
        {
            int area = 1;
            grid[i][j] = 0;
            if (j + 1 < grid[i].size() && grid[i][j + 1] == 1) {
                area += dfs(i, j + 1);
            }
            if (i + 1 < grid.size()  && grid[i + 1][j] == 1) {
                area += dfs(i + 1, j);
            }
            if (j - 1 >= 0 && grid[i][j - 1] == 1) {
                area += dfs(i, j - 1);
            }
            if (i - 1 >= 0  && grid[i - 1][j] == 1) {
                area += dfs(i - 1, j);
            }
            return area;
        };

        int max_area = 0;
        for (size_t i = 0u; i < grid.size(); ++i) {
            for (size_t j = 0u; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1) {
                    max_area = std::max(max_area, dfs(i, j));
                }
            }
        }

        return max_area;    
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
