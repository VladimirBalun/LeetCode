#include "../Helpers.hpp"

// Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
// Return the sorted string. If there are multiple answers, return any of them.

// Example 1:
// Input: s = "tree"
// Output: "eert"
// Explanation: 'e' appears twice while 'r' and 't' both appear once.
// So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

// Example 2:
// Input: s = "cccaaa"
// Output: "aaaccc"
// Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
// Note that "cacaca" is incorrect, as the same characters must be together.

// Example 3:
// Input: s = "Aabb"
// Output: "bbAa"
// Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
// Note that 'A' and 'a' are treated as two different characters.

class Solution
{
public:
    std::string frequencySort(std::string s)
    {
        int max_frequency = 0;
        std::unordered_map<char, int> frequencies{ 0 };
        for (const char letter: s) {
            const int frequency = ++frequencies[letter];
            max_frequency = std::max(max_frequency, frequency);
        }
            
        const auto comparator = [&frequencies](char lhs, char rhs)
        {
            return frequencies[lhs] < frequencies[rhs];
        };

        std::priority_queue<char, std::vector<char>, decltype(comparator)> heap(comparator);
        for (const auto it: frequencies) {
            const char letter = it.first;
            heap.push(letter);
        }

        std::string result;
        result.reserve(s.size());
        while (!heap.empty()) {
            const char letter = heap.top();
            int frequency = frequencies[letter];
            while (frequency > 0) {
                result += letter;
                --frequency;
            }

            heap.pop();
        }

        return result;
    }
};