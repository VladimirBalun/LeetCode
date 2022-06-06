#include "../Helpers.hpp"

// You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.
// An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.
// Return the number of islands in grid2 that are considered sub-islands.

// Example 1:
// Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
// Output: 3
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

// Example 2:
// Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
// Output: 2 
// Explanation: In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
// The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

class Solution {
public:
    int countSubIslands(std::vector<std::vector<int>>& grid1, std::vector<std::vector<int>>& grid2)
    {
        const size_t rows_count = grid2.size();
        const size_t cols_count = grid2[0].size();
        
        std::function<bool(size_t, size_t)> impl;
        impl = [&impl, &grid1, &grid2, rows_count, cols_count] (size_t row, size_t col)
        {
            bool result = true;
            grid2[row][col] = -1;
            if (grid1[row][col] == 0)
                result = false;
            if (row > 0 && grid2[row - 1][col] == 1)
                result &= impl(row - 1, col);
            if (col > 0 && grid2[row][col - 1] == 1)
                result &= impl(row, col - 1);
            if (row < rows_count - 1 && grid2[row + 1][col] == 1)
                result &= impl(row + 1, col);
            if (col < cols_count - 1 && grid2[row][col + 1] == 1)
                result &= impl(row, col + 1);
            return result;
        };
        
        int count_sub_islands = 0;
        for (size_t i = 0u; i < rows_count; ++i) {
            for (size_t j = 0u; j < cols_count; ++j) {
                count_sub_islands += (grid2[i][j] == 1) && impl(i, j);
            }
        }

        return count_sub_islands;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}