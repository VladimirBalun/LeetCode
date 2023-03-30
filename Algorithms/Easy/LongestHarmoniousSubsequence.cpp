#include "../Helpers.hpp"

// We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
// Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.
// A subsequence of array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

// Example 1:
// Input: nums = [1,3,2,2,5,2,3,7]
// Output: 5
// Explanation: The longest harmonious subsequence is [3,2,2,2,3].

// Example 2:
// Input: nums = [1,2,3,4]
// Output: 2

// Example 3:
// Input: nums = [1,1,1,1]
// Output: 0

class Solution
{
public:
    int findLHS(std::vector<int>& nums)
    {
        std::sort(begin(nums), end(nums));

        int left = 0;
        int right = 1;
        int longest_subsequence = 0;
        while (right < nums.size()) {
            const int diff = nums[right] - nums[left];
            if (diff == 1)
                longest_subsequence = std::max(longest_subsequence, right - left + 1);

            if (diff <= 1)
                ++right;
            else
                ++left;
        }

        return longest_subsequence;
    }
};