#include "../Helpers.hpp"

// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.

// Example 1:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true

// Example 2:
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false

class Solution
{
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target)
    {
        if (matrix.empty()) {
            return false;
        }

        const int rows_size = static_cast<int>(matrix.size());
        const int cols_size = static_cast<int>(matrix.front().size());

        int begin = 0;
        int end = rows_size * cols_size - 1;
        while (begin <= end) {
            const int middle = (begin + end) / 2;
            const int current = matrix[middle / cols_size][middle % cols_size];
            if (current < target) {
                begin = middle + 1;
            } else if (current > target) {
                end = middle - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        const std::vector<std::vector<int>> data{
            { 1, 3, 5, 7}, { 10, 11, 16, 20 }, { 23, 30, 34, 60 }
        };
        ASSERT_EQUALS(solution.searchMatrix(data, 3), true);
    }
    {
        const std::vector<std::vector<int>> data{
            { 1, 3, 5, 7}, { 10, 11, 16, 20 }, { 23, 30, 34, 60 }
        };
        ASSERT_EQUALS(solution.searchMatrix(data, 13), false);
    }
    {
        const std::vector<std::vector<int>> data{
            { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 }
        };
        ASSERT_EQUALS(solution.searchMatrix(data, 11), true);
    }
    return EXIT_SUCCESS;
}
