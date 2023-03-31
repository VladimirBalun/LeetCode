#include "../Helpers.hpp"

// Given a 2D grid of size m x n and an integer k. You need to shift the grid k times.

// In one shift operation:
// Element at grid[i][j] moves to grid[i][j + 1].
// Element at grid[i][n - 1] moves to grid[i + 1][0].
// Element at grid[m - 1][n - 1] moves to grid[0][0].
// Return the 2D grid after applying shift operation k times.

// Example 1:
// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[9,1,2],[3,4,5],[6,7,8]]

// Example 2:
// Input: grid = [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]], k = 4
// Output: [[12,0,21,13],[3,8,1,9],[19,7,2,5],[4,6,11,10]]

// Example 3:
// Input: grid = [[1,2,3],[4,5,6],[7,8,9]], k = 9
// Output: [[1,2,3],[4,5,6],[7,8,9]]

class Solution
{
public:
    int toOneDimensional(int cols_size, int row, int col)
    {
        return row * cols_size + col;
    }

    std::pair<int, int> fromOneDimensional(int cols_size, int idx)
    {
        return { idx / cols_size, idx % cols_size };
    }

    std::vector<std::vector<int>> shiftGrid(std::vector<std::vector<int>>& grid, int k)
    {
        const int rows_size = grid.size();
        const int cols_size = grid[0].size();
        const int full_size = rows_size * cols_size;
        std::vector<std::vector<int>> result(rows_size, std::vector<int>(cols_size));

        for (int row = 0; row < rows_size; ++row) {
            for (int col = 0; col < cols_size; ++col) {
                const int idx = toOneDimensional(cols_size, row, col);
                const int position = (idx + k) % full_size;
                const auto res = fromOneDimensional(cols_size, position);
                result[res.first][res.second] = grid[row][col];
            }
        }

        return result;
    }
};