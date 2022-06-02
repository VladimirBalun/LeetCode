#include "../Helpers.hpp"

// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Example 1:
// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

// Example 2:
// Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// Output: 0
// Explanation: All 1s are either on the boundary or can reach the boundary.

class Solution {
public:
    bool is_on_perimeter(size_t row, size_t col, size_t rows_size, size_t cols_size)
    {
        return row == 0u || col == 0u || row == rows_size - 1u || col == cols_size - 1u;
    }
    
    int numEnclaves(vector<vector<int>>& grid)
    {
        const size_t rows_size = grid.size();
        const size_t cols_size = grid[0].size();
        std::function<bool(size_t, size_t, int&)> impl;
        impl = [this, &impl, &grid, rows_size, cols_size] (size_t row, size_t col, int& num_enclaves)
        {
            if (grid[row][col] == 0 || grid[row][col] == -1) {
                return true;
            }
            
            if (grid[row][col] == 1 && is_on_perimeter(row, col, rows_size, cols_size)) {
                return false;
            }

            ++num_enclaves;
            grid[row][col] = -1;
            const bool left = impl(row, col - 1, num_enclaves);
            const bool right = impl(row, col + 1, num_enclaves);
            const bool up = impl(row - 1, col, num_enclaves);
            const bool down = impl(row + 1, col, num_enclaves);
            return left && right && up && down;
        };
        
        int num_enclaves = 0;
        for (size_t i = 1u; i < rows_size - 1u; ++i) {
            for (size_t j = 1u; j < cols_size - 1u; ++j) {
                if (grid[i][j] == 1) {
                    int local_num_enclaves = 0u;
                    if (impl(i, j, local_num_enclaves)) {
                        num_enclaves += local_num_enclaves;
                    }
                }
            }
        }

        return num_enclaves;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}