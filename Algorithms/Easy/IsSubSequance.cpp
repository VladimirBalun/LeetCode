#include "../Helpers.hpp"

// Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
// A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

// Example 1:
// Input: s = "abc", t = "ahbgdc"
// Output: true

// Example 2:
// Input: s = "axc", t = "ahbgdc"
// Output: false

class Solution
{
public:
    bool isSubsequence(std::string source, std::string target)
    {
        if (source.empty()) {
            return true;
        }

        size_t s = 0u;
        for (size_t t = s; (t < target.size()) && (s < source.size()); ++t) {
            if (source[s] == target[t]) {
                ++s;
            }
        }

        return (s == source.size());
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
