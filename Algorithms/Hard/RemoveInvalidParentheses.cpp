#include "../Helpers.hpp"

// Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
// Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

// Example 1:
// Input: s = "()())()"
// Output: ["(())()","()()()"]

// Example 2:
// Input: s = "(a)())()"
// Output: ["(a())()","(a)()()"]

// Example 3:
// Input: s = ")("
// Output: [""]

class Solution
{
public:
    void dfs(
        std::unordered_set<std::string>& parentheses, 
        std::string& path, 
        const std::string& text,
        int counter,
        int idx
    ) {
        if (counter < 0)
            return;

        if (idx == text.size()) {
            if (counter == 0) {
               
                if (parentheses.empty() || path.size() > parentheses.begin()->size()) {
                    parentheses.clear();
                    parentheses.insert(path);
                } else if (parentheses.empty() || path.size() == parentheses.begin()->size()) {
                    parentheses.insert(path);
                }
            }

            return;
        }

        path += text[idx]; 
        if (text[idx] == '(') {
            dfs(parentheses, path, text, counter + 1, idx + 1);
            path.pop_back();
            dfs(parentheses, path, text, counter, idx + 1);
        } else if (text[idx] == ')') {
            dfs(parentheses, path, text, counter - 1, idx + 1);
            path.pop_back();
            dfs(parentheses, path, text, counter, idx + 1);  
        } else {
            dfs(parentheses, path, text, counter, idx + 1);
            path.pop_back();
        }
    }

    std::vector<std::string> removeInvalidParentheses(std::string text)
    {
        std::string path;
        std::unordered_set<std::string> parentheses;
        dfs(parentheses, path, text, 0, 0);

        return { begin(parentheses), end(parentheses) };
    }
};