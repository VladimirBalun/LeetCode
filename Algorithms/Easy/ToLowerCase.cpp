#include "../Helpers.hpp"

// Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

// Example 1:
// Input: s = "Hello"
// Output: "hello"

// Example 2:
// Input: s = "here"
// Output: "here"

// Example 3:
// Input: s = "LOVELY"
// Output: "lovely"

class Solution
{
public:
    std::string toLowerCase(std::string s)
    {
        constexpr uint8_t DIFF = 'a' - 'A';
        for (size_t i = 0u; i < s.size(); ++i) {
            if (s[i] >= 'A' && s[i] <= 'Z')
                s[i] = s[i] + DIFF;
        }
        return s;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
