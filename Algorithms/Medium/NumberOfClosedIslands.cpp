#include "../Helpers.hpp"

// Given a 2D grid consists of 0s (land) and 1s (water).  An island is a maximal 4-directionally connected group of 0s and a closed island is an island totally (all left, top, right, bottom) surrounded by 1s.
// Return the number of closed islands.

// Example 1:
// Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
// Output: 2
// Explanation: 
// Islands in gray are closed because they are completely surrounded by water (group of 1s).

// Example 2:
// Input: grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]
// Output: 1

// Example 3:
// Input: grid = [[1,1,1,1,1,1,1],
//               [1,0,0,0,0,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,1,0,1,0,1],
//               [1,0,1,1,1,0,1],
//               [1,0,0,0,0,0,1],
//               [1,1,1,1,1,1,1]]
// Output: 2

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        const size_t rows_size = grid.size();
        const size_t cols_size = grid[0].size();
        std::function<bool(size_t, size_t)> impl;
        impl = [&impl, &grid, rows_size, cols_size] (size_t row, size_t col)
        {
            if (grid[row][col] == 1 || grid[row][col] == -1) {
                return true;
            }
            
            if (row == 0 || col == 0 || row == rows_size - 1u || col == cols_size - 1u) {
                return false;
            }
            
            grid[row][col] = -1;
            const bool left = impl(row, col - 1);
            const bool right = impl(row, col + 1);
            const bool up = impl(row - 1, col);
            const bool down = impl(row + 1, col);
            return left && right && up && down;
        };
        
        
        int closed_islands = 0;
        for (size_t i = 1u; i < rows_size - 1u; ++i) {
            for (size_t j = 1u; j < cols_size - 1u; ++j) {
                closed_islands += (grid[i][j] == 0) && (impl(i, j));
            }
        }
        
        return closed_islands;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}