#include "../Helpers.hpp"

// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.
// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.
// Return a list of integers representing the size of these parts.

// Example 1:
// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

// Example 2:
// Input: s = "eccbbbbdec"
// Output: [10]

class Solution
{
public:
    std::vector<int> partitionLabels(std::string text)
    {
        std::unordered_map<char, int> last_positions;
        for (int i = 0; i < text.size(); ++i)
            last_positions[text[i]] = i;

        int end_idx = 0;
        int start_idx = 0;
        std::vector<int> result;
        for (int i = 0; i < text.size(); ++i) {
            const int last_idx = last_positions[text[i]];
            end_idx = std::max(end_idx, last_idx);

            if (end_idx == i) {
                result.push_back(end_idx - start_idx + 1);
                start_idx = i + 1;
            }
        }

        return result;
    }
};