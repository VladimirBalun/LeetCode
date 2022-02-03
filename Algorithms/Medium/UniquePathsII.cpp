#include "../Helpers.hpp"

// Input: obstacleGrid = [
//                           [0,0,0],
//                           [0,1,0],
//                           [0,0,0]
//                       ]
// Output: 2
// Explanation: There is one obstacle in the middle of the 3x3 grid above.
// There are two ways to reach the bottom-right corner:
// 1. Right -> Right -> Down -> Down
// 2. Down -> Down -> Right -> Right

// Input: obstacleGrid = [
//                          [0,1],
//                          [0,0]
//                       ]
// Output: 1

// [[0,1],
//  [1,0]]
// Output
// 1
// Expected
// 0

[[0,0,0],
 [0,1,0],
 [0,0,0]]

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacle_grid)
    {
        const size_t row_count = obstacle_grid.size();
        const size_t col_count = obstacle_grid[0].size();

        if (obstacle_grid[0][0] == 1 || obstacle_grid[row_count - 1][col_count - 1] == 1) {
            return 0;
        }

        obstacle_grid[0][0] = 1;
        for (size_t i = 1u; i < row_count; ++i) {
            if (obstacle_grid[i][0] == 1) {
                obstacle_grid[i][0] = 0;
            } else {
                obstacle_grid[i][0] = obstacle_grid[i - 1][0];
            }
        }

        for (size_t j = 1u; j < col_count; ++j) {
            if (obstacle_grid[0][j] == 1) {
                obstacle_grid[0][j] = 0;
            } else {
                obstacle_grid[0][j] = obstacle_grid[0][j - 1];
            }
        }

        for (size_t i = 1u; i < row_count; ++i) {
            for (size_t j = 1u; j < col_count; ++j) {
                if (obstacle_grid[i][j] == 1) {
                    obstacle_grid[i][j] = 0;
                } else {
                    obstacle_grid[i][j] = obstacle_grid[i - 1][j] + obstacle_grid[i][j - 1];
                }
            }
        }

        return obstacle_grid[row_count - 1][col_count - 1];
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
