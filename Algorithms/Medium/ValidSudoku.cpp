#include "../Helpers.hpp"

// Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

// Each row must contain the digits 1-9 without repetition.
// Each column must contain the digits 1-9 without repetition.
// Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

// Note:
// A Sudoku board (partially filled) could be valid but is not necessarily solvable.
// Only the filled cells need to be validated according to the mentioned rules.
 
// Example 1:
// Input: board = 
// [["5","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: true
// Example 2:

// Input: board = 
// [["8","3",".",".","7",".",".",".","."]
// ,["6",".",".","1","9","5",".",".","."]
// ,[".","9","8",".",".",".",".","6","."]
// ,["8",".",".",".","6",".",".",".","3"]
// ,["4",".",".","8",".","3",".",".","1"]
// ,["7",".",".",".","2",".",".",".","6"]
// ,[".","6",".",".",".",".","2","8","."]
// ,[".",".",".","4","1","9",".",".","5"]
// ,[".",".",".",".","8",".",".","7","9"]]
// Output: false
// Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.

class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        std::array<std::array<size_t, 9u>, 9u> cols{ { 0u } };
        std::array<std::array<size_t, 9u>, 9u> rows{ { 0u } };
        std::array<std::array<size_t, 9u>, 9u> boxes{ { 0u } };
        
        for (uint8_t i = 0u; i < 9u; ++i) {
            for (uint8_t j = 0u; j < 9u; ++j) {
                if (std::isdigit(board[i][j])) {
                    const int8_t value = board[i][j] - '0' - 1;

                    if (++rows[i][value] > 1)
                        return false;
                    if (++cols[j][value] > 1)
                        return false;
                    
                    const uint8_t row = i / 3;
                    const uint8_t col = j / 3;
                    const uint8_t box = row * 3 + col;
                    if (++boxes[box][value] > 1)
                        return false;
                }
            }
        }
        
        return true;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
