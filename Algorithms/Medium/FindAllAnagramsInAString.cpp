#include "../Helpers.hpp"

// Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

// Example 1:
// Input: s = "cbaebabacd", p = "abc"
// Output: [0,6]
// Explanation:
// The substring with start index = 0 is "cba", which is an anagram of "abc".
// The substring with start index = 6 is "bac", which is an anagram of "abc".

// Example 2:
// Input: s = "abab", p = "ab"
// Output: [0,1,2]
// Explanation:
// The substring with start index = 0 is "ab", which is an anagram of "ab".
// The substring with start index = 1 is "ba", which is an anagram of "ab".
// The substring with start index = 2 is "ab", which is an anagram of "ab".

class Solution
{
public:
    std::vector<int> findAnagrams(std::string text, std::string anagram)
    {
        if (anagram.size() > text.size())
            return std::vector<int>{};

        std::vector<int> result;
        std::unordered_map<char, int> text_lookup;
        std::unordered_map<char, int> anagram_lookup;
        for (int i = 0; i < anagram.size(); ++i) {
            ++text_lookup[text[i]];
            ++anagram_lookup[anagram[i]];
        }

        if (text_lookup == anagram_lookup)
            result.push_back(0);

        int left = 0;
        for (int right = anagram.size(); right < text.size(); ++right) {
            const char left_letter = text[left];
            const char right_letter = text[right];

            --text_lookup[left_letter];
            ++text_lookup[right_letter];  
            if (text_lookup[left_letter] == 0)
                text_lookup.erase(left_letter);

            ++left;
            if (anagram_lookup == text_lookup)
                result.push_back(left);        
        }

        return result;
    }
};