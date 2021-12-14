#include "../Helpers.hpp"

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.

// Example 1:
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]

// Example 2:
// Input: nums = [0]
// Output: [0]

class Solution
{
public:
    void moveZeroes(vector<int>& nums)
    {
        for (size_t current = 0u, last_zero = 0u; current < nums.size(); ++current) {
            if (nums[current] != 0u) {
                std::swap(nums[last_zero++], nums[current]);
            }
        }
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
