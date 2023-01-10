#include "../Helpers.hpp"

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
// You must do it in place.

// Example 1:
// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

// Example 2:
// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        const int rows_count = matrix.size();
        const int cols_count = matrix[0].size();

        bool first_zero = false;
        for (int row = 0; row < rows_count; ++row) {
            for (int col = 0; col < cols_count; ++col) {
                if (matrix[row][col] == 0) {
                    matrix[0][col] = 0;
                    if (row > 0)
                        matrix[row][0] = 0;
                    else
                        first_zero = true;
                }
            }
        }

        for (int row = 1; row < rows_count; ++row) {
            for (int col = 1; col < cols_count; ++col) {
                if (matrix[row][0] == 0 || matrix[0][col] == 0)
                    matrix[row][col] = 0;
            }
        }

        if (matrix[0][0] == 0) {
            for (int row = 0; row < rows_count; ++row) {
                matrix[row][0] = 0;
            }
        }

        if (first_zero) {
            for (int col = 0; col < cols_count; ++col) {
                matrix[0][col] = 0;
            } 
        }
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}