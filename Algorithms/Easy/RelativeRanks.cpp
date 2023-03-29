#include "../Helpers.hpp"

// You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
// The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:
// The 1st place athlete's rank is "Gold Medal".
// The 2nd place athlete's rank is "Silver Medal".
// The 3rd place athlete's rank is "Bronze Medal".
// For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
// Return an array answer of size n where answer[i] is the rank of the ith athlete.

// Example 1:
// Input: score = [5,4,3,2,1]
// Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
// Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

// Example 2:
// Input: score = [10,3,8,9,4]
// Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
// Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

class Solution
{
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& score)
    {
        std::vector<std::pair<int, int>> temp(score.size());
        for (int i = 0; i < score.size(); ++i) {
            temp[i] = std::pair<int, int>{ score[i], i };
        }

        std::sort(begin(temp), end(temp), std::greater<std::pair<int, int>>());

        std::vector<std::string> result(temp.size());
        result[temp[0].second] = "Gold Medal";
        if (temp.size() > 1)
            result[temp[1].second] = "Silver Medal";
        if (temp.size() > 2)
            result[temp[2].second] = "Bronze Medal";
        for (int i = 3; i < temp.size(); ++i)
            result[temp[i].second] = std::to_string(i + 1);

        return result;
    }
};