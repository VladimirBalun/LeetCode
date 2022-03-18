#include "../Helpers.hpp"

// Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
// The distance between two adjacent cells is 1.

// Example 1:
// Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
// Output: [[0,0,0],[0,1,0],[0,0,0]]

// Example 2:
// Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
// Output: [[0,0,0],[0,1,0],[1,2,1]]

class Solution
{
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat)
    {
        const size_t rows_size = mat.size();
        const size_t cols_size = mat[0].size();

        std::queue<std::pair<int, int>> queue;
        for (size_t i = 0u; i < rows_size; ++i) {
            for (size_t j = 0u; j < cols_size; ++j) {
                if (mat[i][j] == 0)
                    queue.emplace(i, j);
                else
                    mat[i][j] = -1;
            }
        }

        while (!queue.empty()) {
            const auto element = queue.front();
            queue.pop();

            std::vector<std::pair<int, int>> directions{ { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
            for (const auto& direction: directions) {
                const int row = element.first + direction.first;
                const int col = element.second + direction.second;
                if (row >= 0 && row < rows_size && col >= 0 && col < cols_size && mat[row][col] == -1) {
                    mat[row][col] = mat[element.first][element.second] + 1;
                    queue.emplace(row, col);
                }
            } 
        }


        return mat;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
