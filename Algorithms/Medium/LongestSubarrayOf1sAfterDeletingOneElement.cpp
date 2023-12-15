#include "../Helpers.hpp"

// Given a binary array nums, you should delete one element from it.
// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

// Example 1:
// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

// Example 2:
// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

// Example 3:
// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.

class Solution
{
public:
    int longestSubarray(std::vector<int>& nums)
    {
        if (nums.size() < 2)
            return 0;

        int longest_length = 0;

        int left = 0;
        int right = 0;
        int zeroes_number = 0;
        while (right < nums.size()) {
            zeroes_number += (nums[right] == 0);

            while (zeroes_number > 1) {
                zeroes_number -= (nums[left] == 0);
                ++left;
            }

            longest_length = std::max(longest_length, right - left + 1);
            ++right;
        }

        return longest_length - 1;
    }
};