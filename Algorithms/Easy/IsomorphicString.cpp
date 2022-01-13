#include "../Helpers.hpp"

// Given two strings s and t, determine if they are isomorphic.
// Two strings s and t are isomorphic if the characters in s can be replaced to get t.
// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

// Example 1:
// Input: s = "egg", t = "add"
// Output: true

// Example 2:
// Input: s = "foo", t = "bar"
// Output: false

// Example 3:
// Input: s = "paper", t = "title"
// Output: true

class Solution
{
public:
    bool isIsomorphic(const std::string& s, const std::string& t)
    {
        if (s.empty() && t.empty()) {
            return true;
        }

        if (s.size() != t.size()) {
            return false;
        }

        std::unordered_map<char, char> st;
        std::unordered_map<char, char> ts;
        for (size_t i = 0u; i < s.size(); ++i) {
            const char sc = s[i];
            const char tc = t[i];

            if ((st.count(sc) && st[sc] != tc) || (ts.count(tc) && ts[tc] != sc)) {
                return false;
            }

            st[sc] = tc;
            ts[tc] = sc;
        }

        return true;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
