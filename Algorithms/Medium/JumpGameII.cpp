#include "../Helpers.hpp"

// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Your goal is to reach the last index in the minimum number of jumps.
// You can assume that you can always reach the last index.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2

class Solution
{
public:
    int jump(const std::vector<int>& nums)
    {
        size_t left = 0u;
        size_t right = 0u;
        
        int result = 0;
        while (right < nums.size() - 1u) {
            int farthest = 0;
            for (int i = left; i < right + 1; ++i)
                farthest = std::max(farthest, nums[i] + i);
            left = right + 1;
            right = farthest;  
            ++result;
        }
        
        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}