#include "../Helpers.hpp"

// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

// Example 1:
// Input: grid = [
//    ["1","1","1","1","0"],
//    ["1","1","0","1","0"],
//    ["1","1","0","0","0"],
//    ["0","0","0","0","0"]
// ]
// Output: 1

// Example 2:
// Input: grid = [
//     ["1","1","0","0","0"],
//     ["1","1","0","0","0"],
//     ["0","0","1","0","0"],
//     ["0","0","0","1","1"]
// ]
// Output: 3

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>> grid)
    {
        std::function<void(std::vector<std::vector<char>>&, int, int)> bfs_impl;
        bfs_impl = [&bfs_impl](std::vector<std::vector<char>>& grid, int i, int j) {
            if ((i < 0) || (i >= grid.size()) || (j < 0) || (j >= grid[i].size()) || (grid[i][j] == '0')) {
                return;
            }

            grid[i][j] = '0';
            bfs_impl(grid, i + 1, j);
            bfs_impl(grid, i - 1, j);
            bfs_impl(grid, i, j + 1);
            bfs_impl(grid, i, j - 1);
        };

        int count_islands = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1') {
                    ++count_islands;
                    bfs_impl(grid, i, j);
                }
            }
        }

        return count_islands;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        const std::vector<std::vector<char>> grid{
                { '0', '0' },
                { '0', '0' }
        };
        ASSERT_EQUALS(solution.numIslands(grid), 0);
    }
    {
        const std::vector<std::vector<char>> grid{
                { '1', '0' },
                { '0', '1' }
        };
        ASSERT_EQUALS(solution.numIslands(grid), 2);
    }
    {
        const std::vector<std::vector<char>> grid{
                { '1', '0' },
                { '0', '1' },
                { '0', '1' }
        };
        ASSERT_EQUALS(solution.numIslands(grid), 2);
    }
    {
        const std::vector<std::vector<char>> grid{
                { '1', '0', '0' },
                { '0', '1', '1' }
        };
        ASSERT_EQUALS(solution.numIslands(grid), 2);
    }
    {
        const std::vector<std::vector<char>> grid{
                { '1', '1' },
                { '1', '1' }
        };
        ASSERT_EQUALS(solution.numIslands(grid), 1);
    }
    {
        const std::vector<std::vector<char>> grid{
            { '1', '1', '1', '1', '0' },
            { '1', '1', '0', '1', '0' },
            { '1', '1', '0', '0', '0' },
            { '0', '0', '0', '0', '0' }
        };
        ASSERT_EQUALS(solution.numIslands(grid), 1);
    }
    {
        const std::vector<std::vector<char>> grid{
                { '1', '1', '0', '0', '0' },
                { '1', '1', '0', '0', '0' },
                { '0', '0', '1', '0', '0' },
                { '0', '0', '0', '1', '1' }
        };
        ASSERT_EQUALS(solution.numIslands(grid), 3);
    }
    return EXIT_SUCCESS;
}