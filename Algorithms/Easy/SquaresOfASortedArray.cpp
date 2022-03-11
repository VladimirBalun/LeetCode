#include "../Helpers.hpp"

// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:
// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// Example 2:
// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]

class Solution
{
public:
    std::vector<int> sortedSquares(const std::vector<int>& nums)
    {
         std::vector<int> result;
        result.reserve(nums.size());

        ssize_t index = 1;
        ssize_t middle = 0;
        while (index < nums.size() && std::abs(nums[middle]) >= std::abs(nums[index])) {
        	middle = index++;
        }

        ssize_t left = middle - 1;
        ssize_t right = middle + 1;
        result.push_back(nums[middle] * nums[middle]);
        while (result.size() != nums.size()) {
        	if (left < 0) {
        		result.push_back(nums[right] * nums[right]);
        		++right;
        	} else if (right >= nums.size()) {
        		result.push_back(nums[left] * nums[left]);
        		--left;
        	} else {
        		const int left_result = nums[left] * nums[left];
        		const int right_result = nums[right] * nums[right];
        		if (left_result <= right_result) {
       				result.push_back(left_result);
        			--left;
        		} else {
      				result.push_back(right_result);
        			++right;
        		}
        	}
        }

        return result;
    }
};

int main(int argc, char** argv)
{

}
