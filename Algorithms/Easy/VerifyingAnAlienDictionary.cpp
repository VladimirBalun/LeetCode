#include "../Helpers.hpp"

// In an alien language, surprisingly, they also use English lowercase letters, but possibly in a different order. The order of the alphabet is some permutation of lowercase letters.
// Given a sequence of words written in the alien language, and the order of the alphabet, return true if and only if the given words are sorted lexicographically in this alien language.

// Example 1:
// Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
// Output: true
// Explanation: As 'h' comes before 'l' in this language, then the sequence is sorted.

// Example 2:
// Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
// Output: false
// Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1], hence the sequence is unsorted.

// Example 3:
// Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
// Output: false
// Explanation: The first three characters "app" match, and the second string is shorter (in size.) According to lexicographical rules "apple" > "app", because 'l' > '∅', where '∅' is defined as the blank character which is less than any other character (More info).

class Solution
{
    static constexpr uint8_t ALPHABET_SIZE = 26u;
    std::array<uint8_t, ALPHABET_SIZE> lookup;

public:
    bool isAlienSorted(const std::vector<string>& words, const std::string& order)
    {

        for (uint8_t i = 0u; i < order.size(); ++i) {
            const uint8_t symbol_index = order[i] - 'a';
            lookup[symbol_index] = i;
        }

        for (size_t i = 1u; i < words.size(); ++i) {
            if (compare(words[i - 1], words[i]) > 0)
                return false;
        }

        return true;
    }

    int compare(const std::string& word1, const std::string& word2)
    {
        size_t left = 0u;
        size_t right = 0u;
        int compare_result = 0;
        while (left < word1.size() && right < word2.size() && compare_result == 0) {
            const uint8_t left_symbol_index = word1[left++] - 'a';
            const uint8_t right_symbol_index = word2[right++] - 'a';
            compare_result = lookup[left_symbol_index] - lookup[right_symbol_index];
        }

        if (compare_result == 0)
            return word1.size() - word2.size();

        return compare_result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
