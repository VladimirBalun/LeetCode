#include "../Helpers.hpp"

// Given a string s, return the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

class Solution
{
public:
    std::string longestPalindrome(const std::string& s)
    {
        int start = 0;
        int end = 0;

        for (int i = 0; i < s.size(); ++i) {
            const int length_1 = expandFromMiddle(s, i, i);
            const int length_2 = expandFromMiddle(s, i, i + 1);
            const int length = std::max(length_1, length_2);
            if (length > end - start) {
                start = i - (length - 1) / 2;
                end = i + length / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

    int expandFromMiddle(const std::string& s, int left, int right) 
    {
        if (left > right) {
            return 0;
        }

        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }

        return right - left - 1;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
