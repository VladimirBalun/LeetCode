#include "../Helpers.hpp"

// Tic-tac-toe is played by two players A and B on a 3 x 3 grid. The rules of Tic-Tac-Toe are:

// Players take turns placing characters into empty squares ' '.
// The first player A always places 'X' characters, while the second player B always places 'O' characters.
// 'X' and 'O' characters are always placed into empty squares, never on filled ones.
// The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
// The game also ends if all squares are non-empty.
// No more moves can be played if the game is over.
// Given a 2D integer array moves where moves[i] = [rowi, coli] indicates that the ith move will be played on grid[rowi][coli]. return the winner of the game if it exists (A or B). In case the game ends in a draw return "Draw". If there are still movements to play return "Pending".

// You can assume that moves is valid (i.e., it follows the rules of Tic-Tac-Toe), the grid is initially empty, and A will play first.

// Example 1:
// Input: moves = [[0,0],[2,0],[1,1],[2,1],[2,2]]
// Output: "A"
// Explanation: A wins, they always play first.

// Example 2:
// Input: moves = [[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]]
// Output: "B"
// Explanation: B wins.

// Example 3:
// Input: moves = [[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]]
// Output: "Draw"
// Explanation: The game ends in a draw since there are no moves to make.

class Solution
{
public:
    std::string tictactoe(std::vector<std::vector<int>>& moves)
    {
        const int size = moves.size();
        std::vector<int> rows(size);
        std::vector<int> cols(size);

        int player = 1;
        int diagonal_1 = 0;
        int diagonal_2 = 0;
        
        for (int i = 0; i < moves.size(); ++i) {
            const int row = moves[i][0];
            const int col = moves[i][1];

            rows[row] += player;
            cols[col] += player;
            if (row == col)
                diagonal_1 += player;
            if (row + col == 3 - 1)
                diagonal_2 += player;
            
            if (abs(rows[row]) == 3 || abs(cols[col]) == 3 || abs(diagonal_1) == 3 || abs(diagonal_2) == 3) {
                if (player == 1)
                    return "A";
                else
                    return "B";
            }

            player *= -1;
        }

        if (moves.size() == 3 * 3)
            return "Draw";
        else
            return "Pending";
    }
};