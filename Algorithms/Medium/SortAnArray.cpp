#include "../Helpers.hpp"

// Given an array of integers nums, sort the array in ascending order and return it.
// You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

// Example 1:
// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

// Example 2:
// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]
// Explanation: Note that the values of nums are not necessairly unique.

class Solution
{
public:
    void sortArrayImpl(std::vector<int>& nums, int l, int r)
    {
        int leftIdx = l;
        int rightIdx = r;
        int pivot = nums[(l + r) / 2];

        while (leftIdx <= rightIdx) {
            while (leftIdx <= rightIdx && nums[leftIdx] < pivot)
                ++leftIdx;
            while (leftIdx <= rightIdx && nums[rightIdx] > pivot)
                --rightIdx;
            if (leftIdx <= rightIdx)
                std::swap(nums[leftIdx++], nums[rightIdx--]);
        }

        if (rightIdx > l)
            sortArrayImpl(nums, l, rightIdx);
        if (leftIdx < r)
            sortArrayImpl(nums, leftIdx, r);
    }

    std::vector<int> sortArray(std::vector<int>& nums)
    {
        sortArrayImpl(nums, 0, nums.size() - 1);
        return nums;
    }
};