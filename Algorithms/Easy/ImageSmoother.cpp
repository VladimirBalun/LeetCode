#include "../Helpers.hpp"

// An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).
// Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.

// Example 1:
// Input: img = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[0,0,0],[0,0,0],[0,0,0]]
// Explanation:
// For the points (0,0), (0,2), (2,0), (2,2): floor(3/4) = floor(0.75) = 0
// For the points (0,1), (1,0), (1,2), (2,1): floor(5/6) = floor(0.83333333) = 0
// For the point (1,1): floor(8/9) = floor(0.88888889) = 0

// Example 2:
// Input: img = [[100,200,100],[200,50,200],[100,200,100]]
// Output: [[137,141,137],[141,138,141],[137,141,137]]
// Explanation:
// For the points (0,0), (0,2), (2,0), (2,2): floor((100+200+200+50)/4) = floor(137.5) = 137
// For the points (0,1), (1,0), (1,2), (2,1): floor((200+200+50+200+100+100)/6) = floor(141.666667) = 141
// For the point (1,1): floor((50+200+200+200+200+100+100+100+100)/9) = floor(138.888889) = 138

class Solution {
public:
    int calculateNeighbours(std::vector<std::vector<int>>& img, int r, int c)
    {
        int value = 0;
        int count = 0;
        const int rows_size = img.size();
        const int cols_size = img[0].size();
        for (int row = std::max(0, r - 1); row <= std::min(rows_size - 1, r + 1); ++row) {
            for (int col = std::max(0, c - 1); col <= std::min(cols_size - 1, c + 1); ++col) {
                value += img[row][col];
                ++count;
            }
        }

        return value / count;
    }

    std::vector<std::vector<int>> imageSmoother(std::vector<std::vector<int>>& img)
    {
        const int rows_size = img.size();
        const int cols_size = img[0].size();
        std::vector<std::vector<int>> result(rows_size, std::vector<int>(cols_size));

        for (int row = 0; row < rows_size; ++row) {
            for (int col = 0; col < cols_size; ++col) {
                result[row][col] = calculateNeighbours(img, row, col);
            }
        }

        return result;
    }
};