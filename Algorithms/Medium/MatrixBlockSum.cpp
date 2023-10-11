#include "../Helpers.hpp"

// Given a m x n matrix mat and an integer k, return a matrix answer where each answer[i][j] is the sum of all elements mat[r][c] for:
// i - k <= r <= i + k,
// j - k <= c <= j + k, and
// (r, c) is a valid position in the matrix.

// Example 1:
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 1
// Output: [[12,21,16],[27,45,33],[24,39,28]]

// Example 2:
// Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 2
// Output: [[45,45,45],[45,45,45],[45,45,45]]

class Solution {
public:
    std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>>& mat, int k)
    {
        const int rows_number = mat.size();
        const int cols_number = mat[0].size();
        std::vector<std::vector<int>> prefix_sum(
            rows_number + 1, std::vector<int>(cols_number + 1)
        );

        for (int i = 0; i < rows_number; i++) {
            for (int j = 0; j < cols_number; j++) {
                prefix_sum[i + 1][j + 1] = prefix_sum[i][j + 1] + prefix_sum[i + 1][j] - prefix_sum[i][j] + mat[i][j];
            }
        }

        std::vector<std::vector<int>> result(
            rows_number, std::vector<int>(cols_number)
        );

        for (int i = 0; i < rows_number; i++) {
            for (int j = 0; j < cols_number; j++) {
                int row1 = i - k;
                if (row1 < 0)
                    row1 = 0;
                int col1 = j - k;
                if (col1 < 0)
                    col1 = 0;

                int row2 = i + k;
                if (row2 >= rows_number)
                    row2 = rows_number - 1;
                int col2 = j + k;
                if (col2 >= cols_number)
                    col2 = cols_number - 1;

                result[i][j] = prefix_sum[row2 + 1][col2 + 1] - prefix_sum[row2 + 1][col1] - prefix_sum[row1][col2 + 1] + prefix_sum[row1][col1];
            }
        }

        return result;
    }
};