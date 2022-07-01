#include "../Helpers.hpp"

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

// Example 1:
// Input: n = 4
// Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

// Example 2:
// Input: n = 1
// Output: [["Q"]]

class Solution
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::unordered_set<int> cols;
        std::unordered_set<int> negative_diagonals;
        std::unordered_set<int> positive_diagonals;
        
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> board(n, std::string(n, '.'));

        std::function<void(int)> backtracking;
        backtracking = [&backtracking, &result, &board, &cols, &negative_diagonals, &positive_diagonals, n] (int row)
        {
            if (row == n)
                return result.push_back(board);
            
            for (int col = 0; col < n; ++col) {
                if (cols.count(col) != 0 || positive_diagonals.count(row + col) != 0 || negative_diagonals.count(row - col) != 0) 
                    continue;
             
                cols.insert(col);
                positive_diagonals.insert(row + col);
                negative_diagonals.insert(row - col);
                
                board[row][col] = 'Q';
                backtracking(row + 1);
                board[row][col] = '.';

                cols.erase(col);
                positive_diagonals.erase(row + col);
                negative_diagonals.erase(row - col);                                
            }
        };

        backtracking(0);
        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}