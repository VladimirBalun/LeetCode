#include "../Helpers.hpp"

// You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
// Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

// Example 1:
// Input: s1 = "bank", s2 = "kanb"
// Output: true
// Explanation: For example, swap the first character with the last character of s2 to make "bank".

// Example 2:
// Input: s1 = "attack", s2 = "defend"
// Output: false
// Explanation: It is impossible to make them equal with one string swap.

// Example 3:
// Input: s1 = "kelb", s2 = "kelb"
// Output: true
// Explanation: The two strings are already equal, so no string swap operation is required.

class Solution
{
public:
    bool areAlmostEqual(const std::string& s1, const std::string& s2)
    {
        ssize_t left = -1;
        ssize_t right = -1;
        for (size_t i = 0u; i < s1.length(); ++i) {
            if (s1[i] != s2[i]) {
                if (left == -1)
                    left = i;
                else if (right == -1)
                    right = i;
                else
                    return false;
            }
                
        }

        if (left < 0 && right < 0)
            return true;
        if (left < 0 || right < 0)
            return false;

        return s1[left] == s2[right] && s1[right] == s2[left];
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
