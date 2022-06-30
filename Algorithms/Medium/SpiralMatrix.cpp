#include "../Helpers.hpp"

// Given an m x n matrix, return all elements of the matrix in spiral order.

// Example 1:
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]

// Example 2:
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]

class Solution
{
public:
    std::vector<int> spiralOrder(const std::vector<std::vector<int>>& matrix)
    {
        const int rows_size = matrix.size();
        const int cols_size = matrix[0].size();
        
        int top = 0;
        int left = 0;
        int right = cols_size;
        int bottom = rows_size;
        
        std::vector<int> result;
        result.reserve(rows_size * cols_size);
        
        while (left < right && top < bottom) {
            for (int i = left; i < right; ++i)
                result.push_back(matrix[top][i]);
            ++top;
            
            for (int i = top; i < bottom; ++i)
                result.push_back(matrix[i][right - 1]);
            --right;
            
            if (!(left < right && top < bottom))
                break;
            
            for (int i = right - 1; i >= left; --i)
                result.push_back(matrix[bottom - 1][i]);
            --bottom;
            
            for (int i = bottom - 1; i >= top; --i) 
                result.push_back(matrix[i][left]);
            ++left;
        }

        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}