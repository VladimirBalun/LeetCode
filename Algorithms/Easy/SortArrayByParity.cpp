#include "../Helpers.hpp"

// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
// Return any array that satisfies this condition.

// Example 1:
// Input: nums = [3,1,2,4]
// Output: [2,4,3,1]
// Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

// Example 2:
// Input: nums = [0]
// Output: [0]

class Solution
{
public:
    std::vector<int> sortArrayByParity(std::vector<int>& nums)
    {
        size_t left = 0;
        size_t right = nums.size() - 1;
        while (left < right) {
            if (nums[left] % 2 > nums[right] % 2)
                std::swap(nums[left], nums[right]);
            
            if (nums[left] % 2 == 0)
                ++left;
            if (nums[right] % 2 == 1)
                --right;
        }
        
        return nums;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}