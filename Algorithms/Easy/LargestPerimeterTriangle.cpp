#include "../Helpers.hpp"

// Given an integer array nums, return the largest perimeter of a triangle with a non-zero area, formed from three of these lengths. If it is impossible to form any triangle of a non-zero area, return 0.

// Example 1:
// Input: nums = [2,1,2]
// Output: 5

// Example 2:
// Input: nums = [1,2,1]
// Output: 0

class Solution
{
public:
    int largestPerimeter(vector<int>& nums)
    {
        std::sort(begin(nums), end(nums), std::greater<int>());
        for (size_t i = 0u; i < nums.size() - 2u; ++i) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) 
                return nums[i] + nums[i + 1] + nums[i + 2];       
        }

        return 0;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
