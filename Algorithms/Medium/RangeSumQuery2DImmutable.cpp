#include "../Helpers.hpp"

// Given a 2D matrix matrix, handle multiple queries of the following type:

// Calculate the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// Implement the NumMatrix class:

// NumMatrix(int[][] matrix) Initializes the object with the integer matrix matrix.
// int sumRegion(int row1, int col1, int row2, int col2) Returns the sum of the elements of matrix inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
// You must design an algorithm where sumRegion works on O(1) time complexity.

// Example 1:
// Input
// ["NumMatrix", "sumRegion", "sumRegion", "sumRegion"]
// [[[[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]], [2, 1, 4, 3], [1, 1, 2, 2], [1, 2, 2, 4]]
// Output
// [null, 8, 11, 12]

// Explanation
// NumMatrix numMatrix = new NumMatrix([[3, 0, 1, 4, 2], [5, 6, 3, 2, 1], [1, 2, 0, 1, 5], [4, 1, 0, 1, 7], [1, 0, 3, 0, 5]]);
// numMatrix.sumRegion(2, 1, 4, 3); // return 8 (i.e sum of the red rectangle)
// numMatrix.sumRegion(1, 1, 2, 2); // return 11 (i.e sum of the green rectangle)
// numMatrix.sumRegion(1, 2, 2, 4); // return 12 (i.e sum of the blue rectangle)

class NumMatrix {
public:
    NumMatrix(const std::vector<std::vector<int>>& matrix)
    {
        if (matrix.empty())
            return;

        const size_t rows_number = matrix.size();
        const size_t cols_number = matrix[0].size();
        prefix_sum = std::vector<std::vector<int>>(
            rows_number + 1, std::vector<int>(cols_number + 1)
        );

        for (size_t i = 0; i < rows_number; ++i)
            for (size_t j = 0; j < cols_number; j++)
                prefix_sum[i + 1][j + 1] = prefix_sum[i + 1][j] + prefix_sum[i][j + 1] - prefix_sum[i][j] + matrix[i][j];
    }

    
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return prefix_sum[row2 + 1][col2 + 1] - prefix_sum[row2 + 1][col1] - prefix_sum[row1][col2 + 1] + prefix_sum[row1][col1];
    }

private:
    std::vector<std::vector<int>> prefix_sum;
};
