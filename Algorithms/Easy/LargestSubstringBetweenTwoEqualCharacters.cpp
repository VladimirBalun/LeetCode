#include "../Helpers.hpp"

// Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
// A substring is a contiguous sequence of characters within a string.

// Example 1:
// Input: s = "aa"
// Output: 0
// Explanation: The optimal substring here is an empty substring between the two 'a's.

// Example 2:
// Input: s = "abca"
// Output: 2
// Explanation: The optimal substring here is "bc".

// Example 3:
// Input: s = "cbzxy"
// Output: -1
// Explanation: There are no characters that appear twice in s.

class Solution
{
public:
    int maxLengthBetweenEqualCharacters(std::string text)
    {
        int max_length = -1;
        std::unordered_map<char, int> lookup;
        for (int i = 0; i < text.size(); ++i) {
            const char letter = text[i];
            auto it = lookup.find(letter);
            if (it != end(lookup)) {
                const int previous_index = it->second;
                max_length = std::max(max_length, i - previous_index - 1);
            } else {
                lookup[letter] = i;
            }
        }

        return max_length;
    }
};