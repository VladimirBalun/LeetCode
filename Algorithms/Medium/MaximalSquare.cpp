#include "../Helpers.hpp"

// Given an m x n binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

// Example 1:
// Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
// Output: 4

// Example 2:
// Input: matrix = [["0","1"],["1","0"]]
// Output: 1

// Example 3:
// Input: matrix = [["0"]]
// Output: 0

class Solution
{
public:
    int maximalSquare(const std::vector<std::vector<char>>& matrix)
    {
        const size_t row_size = matrix.size();
        const size_t col_size = matrix[0].size();
        
        size_t max_square = 0u;
        std::vector<std::vector<size_t>> cache(row_size + 1u, std::vector<size_t>(col_size + 1u, 0u));

        for (size_t i = 1u; i <= row_size; ++i) {
            for (size_t j = 1u; j <= col_size; ++j) {
                if (matrix[i - 1][j - 1] == '1')
                    cache[i][j] = std::min({cache[i - 1][j - 1], cache[i - 1][j], cache[i][j - 1]}) + 1;
                max_square = std::max(max_square, cache[i][j]);
            }
        }

        return max_square * max_square;
    }
};

int main(int argc, char** argv)
{

}
