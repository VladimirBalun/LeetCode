#include "../Helpers.hpp"

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.

// Example 1:
// Input: s = "()"
// Output: true

// Example 2:
// Input: s = "()[]{}"
// Output: true

// Example 3:
// Input: s = "(]"
// Output: false

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