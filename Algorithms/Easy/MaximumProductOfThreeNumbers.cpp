#include "../Helpers.hpp"

// Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

// Example 1:
// Input: nums = [1,2,3]
// Output: 6

// Example 2:
// Input: nums = [1,2,3,4]
// Output: 24

// Example 3:
// Input: nums = [-1,-2,-3]
// Output: -6

class Solution {
public:
    int maximumProduct(std::vector<int>& nums)
    {
        std::sort(begin(nums), end(nums), std::greater<int>());
        const int first_product = nums[0] * nums[1] * nums[2];
        const int second_product = nums[nums.size() - 1] * nums[nums.size() - 2] * nums[0];
        return std::max(first_product, second_product);
    }
};