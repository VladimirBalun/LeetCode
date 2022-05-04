#include "../Helpers.hpp"

// Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// If target is not found in the array, return [-1, -1].
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]

// Example 2:
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]

// Example 3:
// Input: nums = [], target = 0
// Output: [-1,-1]

class Solution
{
public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target)
    {
        const int left = left_binary_search(nums, target);
        const int right = right_binary_search(nums, target);

        std::vector<int> result{ left, right };
        return result;
    }

    int left_binary_search(const std::vector<int>& nums, int target)
    {
        int left = -1;
        int right = nums.size();

        while (right - left > 1) {
            const int middle = left + (right - left) / 2;
            if (nums[middle] < target) {
                left = middle;
            } else {
                right = middle;
            }
        }

        if (right == nums.size())
            return -1;

        return nums[right] == target ? right : -1;
    }

    int right_binary_search(const std::vector<int>& nums, int target)
    {
        int left = -1;
        int right = nums.size();

        while (right - left > 1) {
            const int middle = left + (right - left) / 2;
            if (nums[middle] <= target) {
                left = middle;
            } else {
                right = middle;
            }
        }

        if (left == -1)
            return -1;

        return nums[left] == target ? left : -1;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
