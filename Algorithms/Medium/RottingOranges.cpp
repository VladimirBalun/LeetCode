#include "../Helpers.hpp"

// You are given an m x n grid where each cell can have one of three values:

// 0 representing an empty cell,
// 1 representing a fresh orange, or
// 2 representing a rotten orange.
// Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

// Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

// Example 1:
// Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
// Output: 4

// Example 2:
// Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
// Output: -1
// Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

// Example 3:
// Input: grid = [[0,2]]
// Output: 0
// Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.

class Solution
{
public:
    int orangesRotting(std::vector<std::vector<int>>& grid)
    {
        const size_t row_size = grid.size();
        const size_t col_size = grid[0].size();

        int fresh_oranges = 0u;
        std::queue<std::pair<int, int>> rotten_oranges;
        for (size_t i = 0u; i < row_size; ++i) {
            for (size_t j = 0u; j < col_size; ++j) {
                if (grid[i][j] == 2) {
                    rotten_oranges.emplace(i, j);
                } else if (grid[i][j] == 1) {
                    ++fresh_oranges;
                }
            }
        }

        const std::vector<std::pair<int, int>> directions{ 
            { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 }
        };

        int minutes_to_rotting = 0;
        while (!rotten_oranges.empty()) {
            bool was_rotten = false;
            const size_t rotten_oranges_size = rotten_oranges.size();
            for (size_t i = 0u; i < rotten_oranges_size; ++i) {
                std::pair<int, int> orange = rotten_oranges.front();
                rotten_oranges.pop();

                for (const auto& dir: directions) {
                    const int row = orange.first + dir.first;
                    const int col = orange.second + dir.second;
                    if (row >= 0 && row < row_size &&
                        col >= 0 && col < col_size &&
                        grid[row][col] == 1) {
                        rotten_oranges.emplace(row, col);
                        grid[row][col] = 2;
                        was_rotten = true;
                        --fresh_oranges;
                    }
                }
            }
            
            if (was_rotten) {
                ++minutes_to_rotting;
            }
        }

        return fresh_oranges == 0 ? minutes_to_rotting : -1;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
