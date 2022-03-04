#include "../Helpers.hpp"

// Given a pattern and a string s, find if s follows the same pattern.
// Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

// Example 1:
// Input: pattern = "abba", s = "dog cat cat dog"
// Output: true

// Example 2:
// Input: pattern = "abba", s = "dog cat cat fish"
// Output: false

// Example 3:
// Input: pattern = "aaaa", s = "dog cat cat dog"
// Output: false

// "aaa"
// "aa aa aa aa"

// "abba"
// "dog cat cat dog"

// "abba"
// "dog dog dog dog"

class Solution
{
public:
    bool wordPattern(const std::string& pattern, const std::string& s)
    {
        size_t start = 0u;
        size_t end = 0u;

        std::array<std::string, 26> symbol_lookup;
        std::unordered_map<std::string, size_t> word_lookup;
        for (const char symbol: pattern) {
            while (end < s.size() && s[end] != ' ') {
                ++end;
            }

            const size_t symbol_index = symbol - 'a';
            std::string word{ begin(s) + start, begin(s) + end };
            
            if (symbol_lookup[symbol_index].empty() && !word_lookup.count(word)) {
                symbol_lookup[symbol_index] = word;
                word_lookup.emplace(std::move(word), symbol_index);
            } else {
                const auto it = word_lookup.find(word);
                if (it == end(word_lookup) ||
                    it.second != symbol_index ||
                    symbol_lookup[symbol_index] != word) {
                    return false;
                }
            }

            start = end = end + 1;
        }

        return end == s.size();
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
