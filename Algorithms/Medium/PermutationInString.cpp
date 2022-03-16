#include "../Helpers.hpp"

// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
// In other words, return true if one of s1's permutations is the substring of s2.

// Example 1:
// Input: s1 = "ab", s2 = "eidbaooo"
// Output: true
// Explanation: s2 contains one permutation of s1 ("ba").

// Example 2:
// Input: s1 = "ab", s2 = "eidboaoo"
// Output: false

class Solution
{
public:
    bool checkInclusion(const std::string& s1, const std::string& s2)
    {
        const size_t s1_length = s1.length();
        const size_t s2_length = s2.length();

        if (s1_length > s2_length) {
            return false;
        }

        std::array<int, 26u> s1_lookup{ 0 };
        std::array<int, 26u> s2_lookup{ 0 };
        for (size_t i = 0u; i < s1_length; ++i) {
            ++s1_lookup[s1[i] - 'a'];
            ++s2_lookup[s2[i] - 'a'];
        }
        
        for (size_t i = 0u; i < s2_length - s1_length; ++i) {
            if (s1_lookup == s2_lookup) {
                return true;
            }

            ++s2_lookup[s2[i + s1_length] - 'a'];
            --s2_lookup[s2[i] - 'a'];
        }

        return s1_lookup == s2_lookup;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
