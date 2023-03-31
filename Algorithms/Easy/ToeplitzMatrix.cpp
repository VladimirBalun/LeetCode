#include "../Helpers.hpp"

// Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.
// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

// Example 1:
// Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
// Output: true
// Explanation:
// In the above grid, the diagonals are:
// "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
// In each diagonal all elements are the same, so the answer is True.

// Example 2:
// Input: matrix = [[1,2],[2,2]]
// Output: false
// Explanation:
// The diagonal "[1, 2]" has different elements.

class Solution
{
public:
    bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix)
    {
        const int rows_size = matrix.size();
        const int cols_size = matrix[0].size();
        for (int row = 0; row < rows_size; ++row) {
            for (int col = 0; col < cols_size; ++col) {
                if (row == 0 || col == 0) {
                    const int value = matrix[row][col];
                    int r = row + 1;
                    int c = col + 1;
                    while (r < rows_size && c < cols_size) {
                        if (matrix[r][c] != matrix[r - 1][c - 1])
                            return false;
                        
                        ++r;
                        ++c;
                    }
                }
            }
        }

        return true;
    }
};