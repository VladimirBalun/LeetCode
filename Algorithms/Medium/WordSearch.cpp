#include "../Helpers.hpp"

// Given an m x n grid of characters board and a string word, return true if word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Example 1:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
// Output: true

// Example 2:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
// Output: true

// Example 3:
// Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
// Output: false

class Solution
{
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word)
    {
        const int rows_size = board.size();
        const int cols_size = board[0].size();
        std::vector<std::vector<bool>> path(rows_size, std::vector<bool>(cols_size));

        std::function<bool(int,int,int)> impl;
        impl = [&impl, &path, &board, &word, rows_size, cols_size] (int row, int col, int index)
        {
            if (index == word.size())
                return true;
            if (row >= rows_size || 
                col >= cols_size || 
                row < 0 || col < 0 || 
                word[index] != board[row][col] ||
                path[row][col])
                return false;
            
            bool result = false;
            path[row][col] = true;
            result |= impl(row + 1, col, index + 1);
            result |= impl(row, col + 1, index + 1);
            result |= impl(row - 1, col, index + 1);
            result |= impl(row, col - 1, index + 1);
            path[row][col] = false;
            return result;
        };

        for (int row = 0; row < rows_size; ++row) {
            for (int col = 0; col < cols_size; ++col) {
                if (impl(row, col, 0))
                    return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}