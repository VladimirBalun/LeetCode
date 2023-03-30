#include "../Helpers.hpp"

// You are given an integer array nums where the largest integer is unique.
// Determine whether the largest element in the array is at least twice as much as every other number in the array. If it is, return the index of the largest element, or return -1 otherwise.

// Example 1:
// Input: nums = [3,6,1,0]
// Output: 1
// Explanation: 6 is the largest integer.
// For every other number in the array x, 6 is at least twice as big as x.
// The index of value 6 is 1, so we return 1.

// Example 2:
// Input: nums = [1,2,3,4]
// Output: -1
// Explanation: 4 is less than twice the value of 3, so we return -1.

class Solution
{
public:
    int dominantIndex(std::vector<int>& nums)
    {
        int max_num = 0;
        int max_num_idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= 2 * max_num) {
                max_num_idx = i;
                max_num = nums[i];  
            } else if (nums[i] > max_num) {
                max_num_idx = -1;
                max_num = nums[i];  
            } else if (nums[i] > max_num / 2) {
                max_num_idx = -1;
            }
        }

        return max_num_idx;
    }
};