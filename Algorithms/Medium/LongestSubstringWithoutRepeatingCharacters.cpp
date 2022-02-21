#include "../Helpers.hpp"

// Given a string s, find the length of the longest substring without repeating characters.

// Example 1:
// Input: s = "abcabcbb"
// Output: 3
// Explanation: The answer is "abc", with the length of 3.

// Example 2:
// Input: s = "bbbbb"
// Output: 1
// Explanation: The answer is "b", with the length of 1.

// Example 3:
// Input: s = "pwwkew"
// Output: 3
// Explanation: The answer is "wke", with the length of 3.
// Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

class Solution
{
public:
    int lengthOfLongestSubstring(const std::string& s)
    {
        int left = 0;
        int right = 0;
        int max = 0;

        std::unordered_set<int> lookup;
        while (right < s.size()) {
            auto it = lookup.find();
            if (!lookup.count(s[right])) {
                lookup.insert(s[right++]);
                max = std::max(max, lookup.size());
            } else {
                lookup.erase(s[left++]);
            }
        }

        return max;
    }
};

int main()
{
    return EXIT_SUCCESS;
}
