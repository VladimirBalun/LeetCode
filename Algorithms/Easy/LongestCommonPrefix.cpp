#include "../Helpers.hpp"

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".

// Example 1:
// Input: strs = ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

class Solution
{
public:
    std::string longestCommonPrefix(const std::vector<std::string>& strs)
    {
        std::string prefix;
        if (strs.empty()) {
            return prefix;
        }

        for (size_t i = 0u; i < strs[0u].size(); ++i) {
            const char symbol = strs[0u][i];
            for (size_t j = 1u; j < strs.size(); ++j) {
                if ((strs[j].size() <= i) || (strs[j][i] != symbol)) {
                    return prefix;
                }
            }
            prefix += symbol;
        }

        return prefix;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
