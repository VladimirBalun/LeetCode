#include "../Helpers.hpp"

// The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.

// Example 1:
// Input: n = 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

// Example 2:
// Input: n = 1
// Output: 1

class Solution
{
public:
    int totalNQueens(int n)
    {
        std::unordered_set<int> cols;
        std::unordered_set<int> positive_diagonals;
        std::unordered_set<int> negative_diagonals;
        
        int combinations = 0;
        std::function<void(int)> backtracking;
        backtracking = [&backtracking, &cols, &positive_diagonals, &negative_diagonals, &combinations, n] (int row)
        {
            if (n == row) {
                ++combinations;
                return;
            }
            
            for (int col = 0; col < n; ++col) {
                const int positive_diagonal = row + col;
                const int negative_diagonal = row - col;
                
                if (cols.count(col) != 0 || 
                    positive_diagonals.count(positive_diagonal) != 0 ||
                    negative_diagonals.count(negative_diagonal) != 0)
                    continue;
                
                cols.insert(col);
                positive_diagonals.insert(positive_diagonal);
                negative_diagonals.insert(negative_diagonal);

                backtracking(row + 1);
                
                cols.erase(col);
                positive_diagonals.erase(positive_diagonal);
                negative_diagonals.erase(negative_diagonal);
            }
        };

        backtracking(0);
        return combinations;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}