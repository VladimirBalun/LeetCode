#include "../Helpers.hpp"

// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.
// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

// Example 1:
// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.

// Example 2:
// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// Output: [12]
// Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.

// Example 3:
// Input: matrix = [[7,8],[1,2]]
// Output: [7]
// Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

class Solution
{
public:
    std::vector<int> luckyNumbers (std::vector<std::vector<int>>& matrix)
    {
        const int rows_size = matrix.size();
        const int cols_size = matrix[0].size();

        std::vector<int> min_rows(rows_size, std::numeric_limits<int>::max());
        std::vector<int> max_cols(cols_size, std::numeric_limits<int>::min());

        for (int row = 0; row < rows_size; ++row) {
            for (int col = 0; col < cols_size; ++col) {
                min_rows[row] = std::min(min_rows[row], matrix[row][col]);
            }
        }

        for (int col = 0; col < cols_size; ++col) {
            for (int row = 0; row < rows_size; ++row) {
                max_cols[col] = std::max(max_cols[col], matrix[row][col]);
            }
        }

        std::vector<int> result;
        for (int row = 0; row < rows_size; ++row) {
            for (int col = 0; col < cols_size; ++col) {
                const int value = matrix[row][col];
                if (value == min_rows[row] && value == max_cols[col])
                    result.push_back(value);
            }
        }

        return result;
    }
};