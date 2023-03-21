#include "../Helpers.hpp"

// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

// Example 1:
// Input: s = "abab"
// Output: true
// Explanation: It is the substring "ab" twice.

// Example 2:
// Input: s = "aba"
// Output: false

// Example 3:
// Input: s = "abcabcabcabc"
// Output: true
// Explanation: It is the substring "abc" four times or the substring "abcabc" twice.

class Solution
{
public:
    bool repeatedSubstringPattern(std::string s)
    {
        std::string temp;
        temp.reserve(s.size());

        int length = s.size();                
        for (int i = length / 2; i > 0; --i) {
            if (length % i == 0) {
                int repeats_number = length / i;
    
                std::string substring(begin(s), begin(s) + i);
                while (repeats_number > 0) {
                    temp += substring;
                    --repeats_number;
                }

                if (temp == s)
                    return true;
                else
                    temp.clear();
            }
        }

        return false;
    }
};