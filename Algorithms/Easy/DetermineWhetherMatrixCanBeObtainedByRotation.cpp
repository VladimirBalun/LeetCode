#include "../Helpers.hpp"

// Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

// Example 1:
// Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
// Output: true
// Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.

// Example 2:
// Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
// Output: false
// Explanation: It is impossible to make mat equal to target by rotating mat.

// Example 3:
// Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
// Output: true
// Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.

class Solution
{
public:
    void rotateMatrix(std::vector<std::vector<int>>& mat)
    {
        const int size = mat.size();
        for (int row = 0; row < size; ++row) {
            for (int col = row; col < size; ++col)
                std::swap(mat[row][col], mat[col][row]);
        }

        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size / 2; ++col)
                std::swap(mat[row][col], mat[row][size - col - 1]);
        }       
    }

    bool findRotation(std::vector<std::vector<int>>& mat, std::vector<std::vector<int>>& target)
    {
        if (mat == target)
            return true;

        const int rotations_count = 3;
        for (int i = 0; i < rotations_count; ++i) {
            rotateMatrix(mat);
            if (mat == target)
                return true;
        }
        
        return false;
    }
};