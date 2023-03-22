#include "../Helpers.hpp"

// Given a string s and an integer k, reverse the first k characters for every 2k characters counting from the start of the string.
// If there are fewer than k characters left, reverse all of them. If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and leave the other as original.

// Example 1:
// Input: s = "abcdefg", k = 2
// Output: "bacdfeg"

// Example 2:
// Input: s = "abcd", k = 2
// Output: "bacd"

class Solution
{
public:
    void reverse(std::string& str, int left, int right)
    {
        while (left <= right)
            std::swap(str[left++], str[right--]);
    }

    std::string reverseStr(std::string s, int k)
    {
        int left = 0;
        while (left < s.size()) {
            int right = left + k;
            if (right > s.size())
                right = s.size();
            
            reverse(s, left, right - 1);
            left += 2 * k;
        }

        return s;
    }
};