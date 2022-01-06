#include "../Helpers.hpp"

// There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
// Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
// The test cases are generated so that the answer will be less than or equal to 2 * 109.

// Example 1:
// Input: m = 3, n = 7
// Output: 28

// Example 2:
// Input: m = 3, n = 2
// Output: 3
// Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
// 1. Right -> Down -> Down
// 2. Down -> Down -> Right
// 3. Down -> Right -> Down

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 && n == 1) {
            return 1;
        }

    	std::vector<std::vector<int>> matrix(m, std::vector<int>(n, 0));
    	for (int i = 0; i < m; ++i) {
    		for (int j = 0; j < n; ++j) {
    			if (i == 0 && j == 0) {
    				continue;
    			} else if (i == 0 || j == 0) {
    				matrix[i][j] = 1;
    			} else {
    				matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1]
    			}
    		}
    	}

    	return matrix[m - 1][n - 1];
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}