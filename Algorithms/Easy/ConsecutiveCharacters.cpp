#include "../Helpers.hpp"

// The power of the string is the maximum length of a non-empty substring that contains only one unique character.
// Given a string s, return the power of s.

// Example 1:
// Input: s = "leetcode"
// Output: 2
// Explanation: The substring "ee" is of length 2 with the character 'e' only.

// Example 2:
// Input: s = "abbcccddddeeeeedcba"
// Output: 5
// Explanation: The substring "eeeee" is of length 5 with the character 'e' only.

class Solution {
public:
    int maxPower(const std::string& s)
    {
        int left = 0;
        int max_power = 0;
        while (left < s.size()) {
            int right = left + 1;
            while (right < s.size() && s[left] == s[right])
                ++right;

            max_power = std::max(max_power, right - left);
            left = right;
        }

        return max_power;
    }
};