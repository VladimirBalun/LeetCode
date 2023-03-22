#include "../Helpers.hpp"

// Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
// In the American keyboard:
// the first row consists of the characters "qwertyuiop",
// the second row consists of the characters "asdfghjkl", and
// the third row consists of the characters "zxcvbnm".

// Example 1:
// Input: words = ["Hello","Alaska","Dad","Peace"]
// Output: ["Alaska","Dad"]

// Example 2:
// Input: words = ["omk"]
// Output: []

// Example 3:
// Input: words = ["adsdf","sfd"]
// Output: ["adsdf","sfd"]

class Solution
{
public:
    std::vector<std::string> findWords(std::vector<std::string>& words)
    {
        static std::vector<std::unordered_set<char>> lookups{
            {'q','w','e','r','t','y','u','i','o','p'},
            {'a','s','d','f','g','h','j','k','l'},
            {'z','x','c','v','b','n','m'},
        };

        std::vector<std::string> result;
        for (const auto& word: words) {
            int symbol_idx = 0;
            int lookup_index = 0;
            for (int i = 0; i < lookups.size(); ++i) {
                const char first_symbol = std::tolower(word[symbol_idx]);
                if (lookups[i].count(first_symbol) != 0) {
                    lookup_index = i;
                    break;
                }
            }

            while (symbol_idx < word.size()) {
                const char symbol = std::tolower(word[symbol_idx]);
                if (lookups[lookup_index].count(symbol) == 0)
                    break;

                ++symbol_idx;
            }

            if (symbol_idx == word.size())
                result.push_back(word);
        }

        return result;
    }
};