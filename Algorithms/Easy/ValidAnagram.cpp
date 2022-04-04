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
        if (s.size() != t.size()) {
            return false;          
        }
        
        std::array<int, 26u> lookup{ 0 };
        for (size_t i = 0u; i < s.size(); ++i) {
            ++lookup[s[i] - 'a'];
            --lookup[t[i] - 'a'];
        }

        for (size_t i = 0u; i < 26u; ++i) {
            if (lookup[i] != 0u) {
                return false;
            }
        }

        return true;
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
