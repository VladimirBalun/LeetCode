#include "../Helpers.hpp"

// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]

// Example 2:
// Input: n = 1
// Output: ["()"]

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::string combination;
        int opened = 0, closed = 0;
        std::vector<std::string> result;
        std::function<void(int, int)> backtracking;
        backtracking = [&backtracking, &result, &combination, n] (int opened, int closed)
        {
            if (opened == n && closed == n)
                return result.push_back(combination);

            if (opened < n) {
                combination += '(';
                backtracking(opened + 1, closed);
                combination.pop_back();
            }
            
            if (closed < opened) {
                combination += ')';
                backtracking(opened, closed + 1);
                combination.pop_back();
            }
        };

        backtracking(0, 0);
        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}