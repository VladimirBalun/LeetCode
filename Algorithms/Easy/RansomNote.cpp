#include "../Helpers.hpp"

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed from magazine and false otherwise.
// Each letter in magazine can only be used once in ransomNote.

// Example 1:
// Input: ransomNote = "a", magazine = "b"
// Output: false

// Example 2:
// Input: ransomNote = "aa", magazine = "ab"
// Output: false

// Example 3:
// Input: ransomNote = "aa", magazine = "aab"
// Output: true

class Solution
{
public:
    bool canConstruct(const std::string& ransomNote, const std::string& magazine)
    {
        std::array<int, 26u> loookup{ 0u };
        for (size_t i = 0u; i < magazine.size(); ++i) {
            ++loookup[magazine[i] - 'a'];
        }

        for (size_t i = 0u; i < ransomNote.size(); ++i) {
            if (--loookup[ransomNote[i] - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
