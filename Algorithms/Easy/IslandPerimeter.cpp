#include "../Helpers.hpp"

// You are given row x col grid representing a map where grid[i][j] = 1 represents land and grid[i][j] = 0 represents water.
// Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).
// The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

// Example 1:
// Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
// Output: 16
// Explanation: The perimeter is the 16 yellow stripes in the image above.

// Example 2:
// Input: grid = [[1]]
// Output: 4

// Example 3:
// Input: grid = [[1,0]]
// Output: 4

class Solution
{
public:
    int dfsImpl(std::vector<std::vector<int>>& grid, int row, int col)
    {
        const int rows_size = grid.size();
        const int cols_size = grid[0].size();
        if (row < 0 || row == rows_size || col < 0 || col == cols_size || grid[row][col] == 0)
            return 1;
        else if (grid[row][col] == 2)
            return 0;

        grid[row][col] = 2;
        return dfsImpl(grid, row + 1, col) +
            dfsImpl(grid, row - 1, col) + 
            dfsImpl(grid, row, col + 1) + 
            dfsImpl(grid, row, col - 1);
    }

    int islandPerimeter(std::vector<std::vector<int>>& grid)
    {
        int perimeter = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == 1)
                    perimeter = dfsImpl(grid, i,  j);
            }
        }

        return perimeter;
    }
};