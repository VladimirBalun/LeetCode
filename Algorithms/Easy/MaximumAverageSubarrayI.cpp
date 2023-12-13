#include "../Helpers.hpp"

// You are given an integer array nums consisting of n elements, and an integer k.
// Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.

// Example 1:
// Input: nums = [1,12,-5,-6,50,3], k = 4
// Output: 12.75000
// Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

// Example 2:
// Input: nums = [5], k = 1
// Output: 5.00000

class Solution
{
public:
    double findMaxAverage(const std::vector<int>& nums, int k)
    {
        if (k > nums.size())
            return 0;

        int current_sum = 0;
        for (int i = 0; i < k; ++i)
            current_sum += nums[i];

        int max_sum = current_sum;
        for (int i = k; i < nums.size(); ++i) {
            current_sum = current_sum + nums[i] - nums[i - k];
            max_sum = std::max(max_sum, current_sum);
        }

        return static_cast<double>(max_sum) / k;
    }
};
