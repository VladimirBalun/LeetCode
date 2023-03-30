#include "../Helpers.hpp"

// Given an array of integers arr, replace each element with its rank.
// The rank represents how large the element is. The rank has the following rules:

// Rank is an integer starting from 1.
// The larger the element, the larger the rank. If two elements are equal, their rank must be the same.
// Rank should be as small as possible.

// Example 1:
// Input: arr = [40,10,20,30]
// Output: [4,1,2,3]
// Explanation: 40 is the largest element. 10 is the smallest. 20 is the second smallest. 30 is the third smallest.

// Example 2:
// Input: arr = [100,100,100]
// Output: [1,1,1]
// Explanation: Same elements share the same rank.

// Example 3:
// Input: arr = [37,12,28,9,100,56,80,5,12]
// Output: [5,3,4,2,8,6,7,1,3]

class Solution
{
public:
    std::vector<int> arrayRankTransform(std::vector<int>& arr)
    {
        if (arr.empty())
            return {};

        std::vector<int> sorted_arr(arr);
        std::sort(begin(sorted_arr), end(sorted_arr));

        std::unordered_map<int, int> ranks;
        ranks.emplace(sorted_arr[0], ranks.size() + 1);
        for (int i = 1; i < sorted_arr.size(); ++i) {
            if (sorted_arr[i] != sorted_arr[i - 1])
                ranks.emplace(sorted_arr[i], ranks.size() + 1);
        }
        
        std::vector<int> result;
        result.reserve(arr.size());
        for (const int number: arr) {
            result.push_back(ranks[number]);
        }

        return result;
    }
};