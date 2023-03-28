#include "../Helpers.hpp"

// Given a string s, return true if the s can be palindrome after deleting at most one character from it.

// Example 1:
// Input: s = "aba"
// Output: true

// Example 2:
// Input: s = "abca"
// Output: true
// Explanation: You could delete the character 'c'.

// Example 3:
// Input: s = "abc"
// Output: false

class Solution {
public:
    bool validPalindromeImpl(string s, int left, int right)
    {
        while (left <= right) {
            if (s[left] != s[right])
                return false;

            ++left;
            --right;
        }

        return true;
    }

    bool validPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;
        bool was_deleted = false;
        while (left <= right) {
            if (s[left] != s[right]) {
                const bool left_result = validPalindromeImpl(s, left + 1, right);
                const bool right_result = validPalindromeImpl(s, left, right - 1);
                return left_result || right_result;
            } else {
                ++left;
                --right;
            }
        }

        return true;
    }
};