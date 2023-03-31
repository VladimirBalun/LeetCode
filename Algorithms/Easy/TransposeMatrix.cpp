#include "../Helpers.hpp"

// Given a 2D integer array matrix, return the transpose of matrix.
// The transpose of a matrix is the matrix flipped over its main diagonal, switching the matrix's row and column indices.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[1,4,7],[2,5,8],[3,6,9]]

// Example 2:
// Input: matrix = [[1,2,3],[4,5,6]]
// Output: [[1,4],[2,5],[3,6]]

class Solution
{
public:
    std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix)
    {
        const int rows_size = matrix.size();
        const int cols_size = matrix[0].size();
        std::vector<std::vector<int>> result(cols_size, std::vector<int>(rows_size));

        for (int row = 0; row < rows_size; ++row) {
            for (int col = 0; col < cols_size; ++col) {
                result[col][row] = matrix[row][col];
            }
        }

        return result;
    }
};