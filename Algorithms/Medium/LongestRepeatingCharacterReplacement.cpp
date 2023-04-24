#include "../Helpers.hpp"

// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
// Return the length of the longest substring containing the same letter you can get after performing the above operations.

// Example 1:
// Input: s = "ABAB", k = 2
// Output: 4
// Explanation: Replace the two 'A's with two 'B's or vice versa.

// Example 2:
// Input: s = "AABABBA", k = 1
// Output: 4
// Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
// The substring "BBBB" has the longest repeating letters, which is 4.

class Solution
{
public:
    int findMaxFrequency(const std::array<int, 26>& frequencies)
    {
        int max_frequency = 0;
        for (int i = 0; i < 26; ++i)
            max_frequency = std::max(max_frequency, frequencies[i]);

        return max_frequency;
    }

    int characterReplacement(std::string text, int k)
    {
        int left = 0;
        int right = 0;
        std::array<int, 26> frequencies{0};

        int longest_substr = 0;
        for (int right = 0; right < text.size(); ++right) {
            ++frequencies[text[right] - 'A'];
            
            int window_length = right - left + 1;
            const int max_frequency = findMaxFrequency(frequencies);
            while (window_length - max_frequency > k) {
                --frequencies[text[left++] - 'A'];
                window_length = right - left + 1;
            }

            longest_substr = std::max(longest_substr, window_length);
        }

        return longest_substr;
    }
};
