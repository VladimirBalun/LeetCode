#include "../Helpers.hpp"

// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

// Example 1:
// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"

// Example 2:
// Input: s = "God Ding"
// Output: "doG gniD"

class Solution
{
public:
    string reverseWords(std::string s)
    {
        size_t word_begin = 0u;
        for (size_t i = 0u; i < s.length(); ++i) {
            if (s[i] == ' ') {
                size_t word_end = i - 1u;
                while (word_begin < word_end) {
                    std::swap(s[word_begin++], s[word_end--]);
                }
                word_begin = i + 1;
            }
        }

        size_t word_end = s.length() - 1u;
        while (word_begin < word_end) {
            std::swap(s[word_begin++], s[word_end--]);
        }        

        return s;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
