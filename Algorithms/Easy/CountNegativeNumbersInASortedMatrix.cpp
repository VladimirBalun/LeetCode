#include "../Helpers.hpp"

// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

// Example 1:
// Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.

// Example 2:
// Input: grid = [[3,2],[1,0]]
// Output: 0

class Solution
{
public:
    int countNegatives(const std::vector<std::vector<int>>& grid)
    {
    	const int rows_size = grid.size();
    	const int cols_size = grid[0].size();
        
        int count = 0;
        for (int i = rows_size - 1u; i >= 0; --i) {
        	int left = -1;
        	int right = cols_size;
        	while (right - left > 1) {
        		int middle = left + (right - left) / 2;
        		if (grid[i][middle] <= -1) {
        			right = middle;
        		} else {
        			left = middle;
        		}
        	}

        	if (right == cols_size)
        		break;

        	count += cols_size - right;
        }

        return count;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}
