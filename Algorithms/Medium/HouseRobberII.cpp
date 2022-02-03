#include "../Helpers.hpp"

// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

// Example 1:
// Input: nums = [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.

// Example 2:
// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.

// Example 3:
// Input: nums = [1,2,3]
// Output: 3

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 1) {
            return nums[0];
        }

        const size_t size = nums.size();
        std::function<int(std::vector<int>, size_t, size_t)> impl;
        impl = [&impl, size] (vector<int> nums, size_t left, size_t right)
        {
            if (left == right) {
                return nums[left];
            }

            nums[left + 1] = std::max(nums[left], nums[left + 1]);
            for (size_t i = left + 2; i <= right; ++i) {
                nums[i] = std::max(nums[i - 1u], nums[i] + nums[i - 2u]);
            }
            return nums[right];
        };

        return std::max(impl(nums, 0u, size - 2u), impl(nums, 1u, size - 1u));
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
