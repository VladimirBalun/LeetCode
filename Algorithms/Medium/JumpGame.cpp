#include "../Helpers.hpp"

// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
// Return true if you can reach the last index, or false otherwise.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

class Solution {
public:
    bool canJump(const std::vector<int>& nums)
    {
        int goal_index = nums.size() - 1;
        for (int i = goal_index - 1; i >= 0; --i) {
            const int count_steps = nums[i];
            if (i + count_steps >= goal_index) 
                goal_index = i;
        }
        
        return goal_index == 0;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}