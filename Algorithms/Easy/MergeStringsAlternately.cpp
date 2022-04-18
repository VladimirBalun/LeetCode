#include "../Helpers.hpp"

// You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.
// Return the merged string.

// Example 1:
// Input: word1 = "abc", word2 = "pqr"
// Output: "apbqcr"
// Explanation: The merged string will be merged as so:
// word1:  a   b   c
// word2:    p   q   r
// merged: a p b q c r

// Example 2:
// Input: word1 = "ab", word2 = "pqrs"
// Output: "apbqrs"
// Explanation: Notice that as word2 is longer, "rs" is appended to the end.
// word1:  a   b 
// word2:    p   q   r   s
// merged: a p b q   r   s

// Example 3:
// Input: word1 = "abcd", word2 = "pq"
// Output: "apbqcd"
// Explanation: Notice that as word1 is longer, "cd" is appended to the end.
// word1:  a   b   c   d
// word2:    p   q 
// merged: a p b q c   d

class Solution
{
public:
    std::string mergeAlternately(const std::string& word1, const std::string& word2)
    {
        const size_t left_word_size = word1.size();
        const size_t right_word_size = word2.size();

        std::string merged;
        merged.reserve(left_word_size + right_word_size);

        size_t left = 0u;
        size_t right = 0u;
        while (left < left_word_size && right < right_word_size) {
            merged += word1[left++];
            merged += word2[right++];
        }

        while (left < left_word_size)
            merged += word1[left++];

        while (right < right_word_size)
            merged += word2[right++];     

        return merged;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
