#include "../Helpers.hpp"

// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// A subarray is a contiguous part of an array.

// Example 1:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.

// Example 2:
// Input: nums = [1]
// Output: 1

// Example 3:
// Input: nums = [5,4,-1,7,8]
// Output: 23

class Solution
{
public:
    int maxSubArray(std::vector<int>& nums)
    {
        int max_sum = nums[0u];
        int current_sum = max_sum;
        for (size_t i = 1u; i < nums.size(); ++i) {
            current_sum = std::max(nums[i], current_sum + nums[i]);
            max_sum = std::max(max_sum, current_sum);
        }
 
        return max_sum;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
