#include "../Helpers.hpp"

// Implement strStr().
// Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

// Clarification:
// What should we return when needle is an empty string? This is a great question to ask during an interview.
// For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

// Example 1:
// Input: haystack = "hello", needle = "ll"
// Output: 2

// Example 2:
// Input: haystack = "aaaaa", needle = "bba"
// Output: -1

// Example 3:
// Input: haystack = "", needle = ""
// Output: 0


class Solution 
{
public:
    int strStr(const std::string& haystack, const std::string& needle) 
    {
        if (needle.empty()) {
            return 0;
        } else if ((haystack.empty()) || (haystack.size() < needle.size())) {
            return -1;
        }

        for (size_t i = 0u; i < haystack.size(); ++i) {
            if (haystack[i] == needle[0u]) {
                size_t j = 0u;
                for (size_t k = i; (k < haystack.size()) && (j < needle.size()); ++j, ++k) {
                    if (haystack[k] != needle[j]) {
                        break;
                    }
                }
                if (j == needle.size()) {
                    return i;
                }
            }
        }

        return -1;
    }
};

int main(int argc, char** argv)
{
    strStr("mississippi", "issip");
    return EXIT_SUCCESS;
}
