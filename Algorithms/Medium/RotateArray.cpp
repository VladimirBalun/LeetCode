#include "../Helpers.hpp"

// Given an array, rotate the array to the right by k steps, where k is non-negative.

// Example 1:
// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
// Explanation:
// rotate 1 steps to the right: [7,1,2,3,4,5,6]
// rotate 2 steps to the right: [6,7,1,2,3,4,5]
// rotate 3 steps to the right: [5,6,7,1,2,3,4]

// Example 2:
// Input: nums = [-1,-100,3,99], k = 2
// Output: [3,99,-1,-100]
// Explanation: 
// rotate 1 steps to the right: [99,-1,-100,3]
// rotate 2 steps to the right: [3,99,-1,-100]

class Solution 
{
public:
    void rotate(std::vector<int>& nums, size_t k)
    {
        if ((k == 0u) || (nums.empty())) {
            return;
        }

        const auto reverse = [&nums](size_t left, size_t right)
        {
            while (left < right) {
                std::swap(nums[left++], nums[right--]);
            }
        };

        const size_t offset = k % nums.size();
        if (offset != 0u) {
            reverse(0u, nums.size() - 1u);
            reverse(0u, offset - 1u);
            reverse(offset, nums.size() - 1u);
        }
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}

