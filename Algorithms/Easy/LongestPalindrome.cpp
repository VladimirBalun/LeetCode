#include "../Helpers.hpp"

// Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
// Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

// Example 1:
// Input: s = "abccccdd"
// Output: 7
// Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

// Example 2:
// Input: s = "a"
// Output: 1
// Explanation: The longest palindrome that can be built is "a", whose length is 1.

class Solution {
public:
    int longestPalindrome(std::string s)
    {
        if (s.empty())
            return 0;

        std::unordered_map<char, int> lookup;
        for (int i = 0; i < s.size(); ++i)
            ++lookup[s[i]];
        
        int even = 0;
        int odd = 0;
        for (const auto it: lookup) {
            const int count = it.second;
            even += (count & (~1));
            odd |= (count & 1);
        }

        return even + odd;
    }
};