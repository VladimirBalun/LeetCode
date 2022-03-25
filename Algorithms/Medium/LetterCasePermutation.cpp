#include "../Helpers.hpp"

// Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.
// Return a list of all possible strings we could create. Return the output in any order.

// Example 1:
// Input: s = "a1b2"
// Output: ["a1b2","a1B2","A1b2","A1B2"]

// Example 2:
// Input: s = "3z4"
// Output: ["3z4","3Z4"]

class Solution
{
public:
    std::vector<std::string> letterCasePermutation(string s)
    {
        std::vector<std::string> result;
        std::function<void(size_t)> backtracking;
        backtracking = [&backtracking, &result, &s](size_t index)
        {
            if (index == s.size())
               return result.push_back(s);

            backtracking(index + 1);
            if (!std::isdigit(s[index])) {
                s[index] = std::isupper(s[index]) 
                    ? std::tolower(s[index]) : std::toupper(s[index]);
                backtracking(index + 1);
            }
        };

        backtracking(0u);
        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
