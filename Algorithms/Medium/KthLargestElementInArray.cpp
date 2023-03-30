#include "../Helpers.hpp"

// Given an integer array nums and an integer k, return the kth largest element in the array.
// Note that it is the kth largest element in the sorted order, not the kth distinct element.
// You must solve it in O(n) time complexity.

// Example 1:
// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5

// Example 2:
// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4

class Solution
{
public:
    int quickSelectImpl(std::vector<int>& nums, int l, int r, int k)
    {
        int left_idx = l;
        int right_idx = r;
        int pivot_idx = left_idx++;
        int pivot = nums[pivot_idx];

        while (left_idx <= right_idx) {
            while (left_idx <= right_idx && nums[left_idx] >= pivot)
                ++left_idx;
            while (left_idx <= right_idx && nums[right_idx] < pivot)
                --right_idx;

            if (left_idx <= right_idx)
                std::swap(nums[left_idx], nums[right_idx]);
        }

        std::swap(nums[right_idx], nums[pivot_idx]);

        if (right_idx > k)
            return quickSelectImpl(nums, l, right_idx - 1, k);
        else if (right_idx < k)
            return quickSelectImpl(nums, right_idx + 1, r, k);
        else
            return nums[right_idx];
    }

    int findKthLargest(std::vector<int>& nums, int k)
    {
        return quickSelectImpl(nums, 0, nums.size() - 1, k - 1);
    }
};