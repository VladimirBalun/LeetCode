#include "../Helpers.hpp"

// Given a binary array nums, return the maximum number of consecutive 1's in the array.

// Example 1:
// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

// Example 2:
// Input: nums = [1,0,1,1,0,1]
// Output: 2

class Solution
{
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums)
    {
        int consecutive_ones = 0;
        int max_consecutive_ones = 0;
        for (const int num: nums) {
            if (num == 1) {
                ++consecutive_ones;
                max_consecutive_ones = std::max(max_consecutive_ones, consecutive_ones);
            } else {
                consecutive_ones = 0;
            }
        }

        return max_consecutive_ones;
    }
};