#include "../Helpers.hpp"

// Given an array of strings words and an integer k, return the k most frequent strings.
// Return the answer sorted by the frequency from highest to lowest. Sort the words with the same frequency by their lexicographical order.

// Example 1:
// Input: words = ["i","love","leetcode","i","love","coding"], k = 2
// Output: ["i","love"]
// Explanation: "i" and "love" are the two most frequent words.
// Note that "i" comes before "love" due to a lower alphabetical order.

// Example 2:
// Input: words = ["the","day","is","sunny","the","the","the","sunny","is","is"], k = 4
// Output: ["the","is","sunny","day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words, with the number of occurrence being 4, 3, 2 and 1 respectively.

class Solution
{
public:
    std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k)
    {
        std::unordered_map<std::string, int> frequencies;
        for (const auto& word: words)
            ++frequencies[word];

        const auto comparator = [&frequencies](const std::string& lhs, const std::string& rhs)
        {
            const int left_frequency = frequencies[lhs];
            const int right_frequency = frequencies[rhs];
            if (left_frequency == right_frequency)
                return lhs > rhs;
            else
                return left_frequency < right_frequency;
        };

        std::priority_queue<std::string, std::vector<std::string>, decltype(comparator)> heap(comparator);
        for (const auto& it: frequencies)
            heap.push(it.first);
 
        std::vector<std::string> result;
        result.reserve(k);
        while (k > 0) {
            result.push_back(heap.top());
            heap.pop();
            --k;
        }

        return result;
    }
};