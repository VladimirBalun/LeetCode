#include "../Helpers.hpp"

// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

// Example 1:
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Example 2:
// Input: nums = [2,0,1]
// Output: [0,1,2]

class Solution
{
public:
    void sortColors(std::vector<int>& nums)
    {
        if (nums.size() <= 1u) {
            return;
        }

        int left = 0;
        int current = 0;
        int right = nums.size() - 1;
        while (current <= right) {
            if (nums[current] == 0) {
                std::swap(nums[left++], nums[current++]);
            } else if (nums[current] == 2) {
                std::swap(nums[right--], nums[current]);
            } else {
                ++current;
            }
        }
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
