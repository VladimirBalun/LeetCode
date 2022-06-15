#include "../Helpers.hpp"

// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.

// Example 1:
// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

// Example 2:
// Input: nums = [0,0,0], target = 1
// Output: 0

class Solution
{
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        std::sort(begin(nums), end(nums));

        int closest_sum = nums[0] + nums[1] + nums[2];
        for (size_t i = 0u; i < nums.size() - 2u; ++i) {
        	size_t left = i + 1;
        	size_t right = nums.size() - 1u;
        	while (left < right) {
        		const int current_sum = nums[i] + nums[left] + nums[right];
        		if (current_sum > target) {
        			--right;
        		} else {
        			++left;
        		}

        		if (std::abs(target - current_sum) < std::abs(target - closest_sum)) {
        			closest_sum = current_sum;
        		}
        	}
        }

        return closest_sum;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}