#include "../Helpers.hpp"

// Given a string s of '(' , ')' and lowercase English characters.
// Your task is to remove the minimum number of parentheses ( '(' or ')', in any positions ) so that the resulting parentheses string is valid and return any valid string.

// Formally, a parentheses string is valid if and only if:
// It is the empty string, contains only lowercase characters, or
// It can be written as AB (A concatenated with B), where A and B are valid strings, or
// It can be written as (A), where A is a valid string.

// Example 1:
// Input: s = "lee(t(c)o)de)"
// Output: "lee(t(c)o)de"
// Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

// Example 2:
// Input: s = "a)b(c)d"
// Output: "ab(c)d"

// Example 3:
// Input: s = "))(("
// Output: ""
// Explanation: An empty string is also valid.

class Solution
{
public:
    std::string minRemoveToMakeValid(std::string text)
    {
        std::stack<int> stack;
        for (int i = 0; i < text.size(); i++) {
            const char symbol = text[i];
            if (symbol == '(') {
                stack.push(i);
            } else if (symbol == ')') {
                if (stack.empty())
                    text[i] = '_';
                else
                    stack.pop();
            }
        }

        while (!stack.empty()) {
            const int idx = stack.top();
            stack.pop();

            text[idx] = '_';
        }

        int left = 0;
        int right = 0;
        while (right < text.size()) {
            while (right < text.size() && text[right] == '_')
                ++right;

            if (right < text.size())
                text[left++] = text[right++];
        }

        text.resize(std::max(left, 0));
        return text;
    }
};