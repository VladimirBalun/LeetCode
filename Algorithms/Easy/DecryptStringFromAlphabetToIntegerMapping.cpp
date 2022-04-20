#include "../Helpers.hpp"

// You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:
// Characters ('a' to 'i') are represented by ('1' to '9') respectively.
// Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
// Return the string formed after mapping.
// The test cases are generated so that a unique mapping will always exist.

// Example 1:
// Input: s = "10#11#12"
// Output: "jkab"
// Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

// Example 2:
// Input: s = "1326#"
// Output: "acz"

class Solution
{
public:
    string freqAlphabets(const std::string& s)
    {
        std::string result;
        for (size_t i = 0u; i < s.size();) {
            if (i + 2 < s.size() && s[i + 2] == '#') {
                const size_t number = (s[i] - '0') * 10 + (s[i + 1] - '0');
                result += 'a' + number - 1;
                i += 3;
            } else {
                result += 'a' + (s[i] - '0') - 1;
                ++i;
            }
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
