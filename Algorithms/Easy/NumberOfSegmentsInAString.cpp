#include "../Helpers.hpp"

// Given a string s, return the number of segments in the string.
// A segment is defined to be a contiguous sequence of non-space characters.

// Example 1:
// Input: s = "Hello, my name is John"
// Output: 5
// Explanation: The five segments are ["Hello,", "my", "name", "is", "John"]

// Example 2:
// Input: s = "Hello"
// Output: 1

class Solution
{
public:
    int countSegments(std::string s)
    {
        int count_segments = 0;
        for (int i = 0; i < s.size(); ++i) {
            if ((i == 0 || std::isspace(s[i - 1])) && !std::isspace(s[i]))
                ++count_segments;
        }

        return count_segments;
    }
};