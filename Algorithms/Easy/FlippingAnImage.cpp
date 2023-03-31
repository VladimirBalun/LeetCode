#include "../Helpers.hpp"

// Given an n x n binary matrix image, flip the image horizontally, then invert it, and return the resulting image.
// To flip an image horizontally means that each row of the image is reversed.
// For example, flipping [1,1,0] horizontally results in [0,1,1].
// To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0.
// For example, inverting [0,1,1] results in [1,0,0].

// Example 1:
// Input: image = [[1,1,0],[1,0,1],[0,0,0]]
// Output: [[1,0,0],[0,1,0],[1,1,1]]
// Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
// Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]

// Example 2:
// Input: image = [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
// Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
// Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
// Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]

class Solution
{
public:
    std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image)
    {
        const int rows_size = image.size();
        const int cols_size = image[0].size();
        for (int row = 0; row < rows_size; ++row) {
            for (int col = 0; col < (cols_size + 1) / 2; ++col) {
                int temp = image[row][col];
                image[row][col] = 1 - image[row][cols_size - col - 1];
                image[row][cols_size - col - 1] = 1 - temp;
            }
        }

        return image;
    }
};