#include "../Helpers.hpp"

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// Example 1:
// Input: s = "anagram", t = "nagaram"
// Output: true

// Example 2:
// Input: s = "rat", t = "car"
// Output: false

class Solution
{
public:
    bool isAnagram(const std::string& s, const std::string& t)
    {
        if (s.length() != t.length()) {
            return false;
        }

        constexpr size_t ALPHABET_COUNT = 26u;
        std::array<int, ALPHABET_COUNT> symbols{};
        for (const char symbol : s) {
            ++symbols[symbol - 'a'];
        }

        for (const char symbol : t) {
            --symbols[symbol - 'a'];
        }

        return std::all_of(symbols.cbegin(), symbols.cend(), [](int count){ return count == 0; });
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    ASSERT_EQUALS(solution.isAnagram("", ""), true);
    ASSERT_EQUALS(solution.isAnagram("anagram", "nagaram"), true);
    ASSERT_EQUALS(solution.isAnagram("anagram", "nagaran"), false);
    ASSERT_EQUALS(solution.isAnagram("anagram", "nagarana"), false);
    return EXIT_SUCCESS;
}
