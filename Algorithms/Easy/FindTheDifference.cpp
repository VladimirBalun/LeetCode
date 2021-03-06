#include "../Helpers.hpp"

// You are given two strings s and t.
// String t is generated by random shuffling string s and then add one more letter at a random position.
// Return the letter that was added to t.

// Example 1:
// Input: s = "abcd", t = "abcde"
// Output: "e"
// Explanation: 'e' is the letter that was added.

// Example 2:
// Input: s = "", t = "y"
// Output: "y"
 
class Solution
{
public:
    char findTheDifference(const std::string& s, const std::string& t)
    {
        constexpr uint8_t ALPHABET_SIZE = 26u;
        std::array<size_t, ALPHABET_SIZE> lookup{ 0u };
        
        for (size_t i = 0u; i < t.size(); ++i)
            ++lookup[t[i] - 'a'];

        for (size_t i = 0u; i < s.size(); ++i)
            --lookup[s[i] - 'a'];
        
        for (size_t i = 0u; i < ALPHABET_SIZE; ++i) {
            if (lookup[i] == 1u)
                return static_cast<char>(i + 'a');
        }

        return '!';
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
