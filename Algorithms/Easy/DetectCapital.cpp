#include "../Helpers.hpp"

// We define the usage of capitals in a word to be right when one of the following cases holds:
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital, like "Google".
// Given a string word, return true if the usage of capitals in it is right.

// Example 1:
// Input: word = "USA"
// Output: true

// Example 2:
// Input: word = "FlaG"
// Output: false

class Solution
{
public:
    bool detectCapitalUse(std::string word)
    {
        if (word.size() == 1)
            return true;

        if (std::isupper(word[0]) && std::isupper(word[1])) {
            for (int i = 2; i < word.size(); ++i) {
                if (!std::isupper(word[i]))
                    return false;
            }
        } else {
            for (int i = 1; i < word.size(); ++i) {
                if (std::isupper(word[i]))
                    return false;
            }            
        }

        return true;
    }
};