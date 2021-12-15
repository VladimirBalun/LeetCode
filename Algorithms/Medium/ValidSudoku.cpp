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
        constexpr size_t BOX_SIZE = 9u;
        constexpr size_t PART_SIZE = BOX_SIZE / 3u;

        std::array<std::array<size_t, BOX_SIZE>, BOX_SIZE> cols{ 0u };
        std::array<std::array<size_t, BOX_SIZE>, BOX_SIZE> rows{ 0u };
        std::array<std::array<size_t, BOX_SIZE>, BOX_SIZE> boxes{ { 0u } };

        for (size_t i = 0u; i < board.size(); ++i) {
            for (size_t j = 0u; j < board[i].size(); ++j) {
                const char value = board[i][j];
                if (std::isdigit(value)) {
                    const size_t row = i / PART_SIZE;
                    const size_t col = j / PART_SIZE;
                    const size_t box = row * PART_SIZE + col;

                    ++cols[i][value - '0' - 1u];
                    ++rows[j][value - '0' - 1u];
                    ++boxes[box][value - '0' - 1u];

                    if ((cols[i][value - '0' - 1u] > 1u) || 
                        (rows[j][value - '0' - 1u] > 1u) ||
                        (boxes[box][value - '0' - 1u] > 1u)) {
                        return false;
                    }
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
