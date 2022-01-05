#include "../Helpers.hpp"

// Given an array nums of size n, return the majority element.
// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Example 1:
// Input: nums = [3,2,3]
// Output: 3

// Example 2:
// Input: nums = [2,2,1,1,1,2,2]
// Output: 2

class Solution 
{
public:
    int majorityElement(const std::vector<int>& nums) 
    {
        const size_t half = nums.size() / 2u;
        std::unordered_map<size_t, size_t> lookup;
        for (const int num : nums) {
            if (++lookup[num] > half) {
                return num;
            }
        }
        return -1;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}