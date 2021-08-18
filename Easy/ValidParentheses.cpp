#include <stack>
#include <iostream>

#include "../Helpers.hpp"

class Solution
{
public:
    bool isValid(const std::string& s)
    {
        std::stack<char> parentheses;
        for (const char sym : s) {
            if ((sym == '(') || (sym == '[') || (sym == '{')) {
                parentheses.push(sym);
            } else if (!parentheses.empty()) {
                const char last_sym = parentheses.top();
                if (((last_sym == '(') && (sym == ')'))
                    || ((last_sym == '[') && (sym == ']'))
                    || ((last_sym == '{') && (sym == '}'))) {
                    parentheses.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }

        return parentheses.empty();
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    ASSERT_EQUALS(solution.isValid(""), true);
    ASSERT_EQUALS(solution.isValid("()"), true);
    ASSERT_EQUALS(solution.isValid("()[]{}"), true);
    ASSERT_EQUALS(solution.isValid("(]"), false);
    ASSERT_EQUALS(solution.isValid("([)]"), false);
    ASSERT_EQUALS(solution.isValid("{[]}"), true);
    ASSERT_EQUALS(solution.isValid("]{[]}"), false);
    return EXIT_SUCCESS;
}