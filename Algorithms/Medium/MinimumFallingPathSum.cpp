#include "../Helpers.hpp"

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 
// Example 1:
// Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
// Output: 13
// Explanation: There are two falling paths with a minimum sum as shown.

// Example 2:
// Input: matrix = [[-19,57],[-40,-5]]
// Output: -59
// Explanation: The falling path with a minimum sum is shown.

class Solution
{
public:
    int minFallingPathSum(std::vector<std::vector<int>>& matrix)
    {
        for (size_t i = 1u; i < matrix.size(); ++i) {
            for (size_t j = 0u; j < matrix[i].size(); ++j) {
                const int up = matrix[i - 1][j];
                const int left_up = (j > 0u) ? (matrix[i - 1][j - 1]) : (std::numeric_limits<int>::max());
                const int right_up = (j < matrix[i].size() - 1) ? (matrix[i - 1][j + 1]) : (std::numeric_limits<int>::max());
                matrix[i][j] = matrix[i][j] + std::min(std::min(left_up, up), right_up);
            }
        }

        const size_t last_row = matrix.size() - 1u;
        return *std::min_element(matrix[last_row].begin(), matrix[last_row].end());
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
