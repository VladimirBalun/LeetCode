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
        int left = 0;
        int right = nums.size() - 1;
        int insert_index = right;
        std::vector<int> result(nums.size());
        
        while (left <= right) {
            const auto left_value = nums[left];
            const auto right_value = nums[right];
            if (abs(left_value) <= abs(right_value)) {
                result[insert_index] = right_value * right_value;
                --right;
            } else {
                result[insert_index] = left_value * left_value;
                ++left;
            } 

            --insert_index;
        }
        
        return result;
    }
};

int main(int argc, char** argv)
{

}
