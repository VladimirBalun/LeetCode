#include "../Helpers.hpp"

// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:
// Input: nums = [2,2,1]
// Output: 1

// Example 2:
// Input: nums = [4,1,2,1,2]
// Output: 4

// Example 3:
// Input: nums = [1]
// Output: 1

class Solution
{
public:
    int singleNumber(const std::vector<int>& nums)
    {
        int single_number = 0;
        for (const auto number : nums) {
            single_number ^= number;
        }
        return single_number;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    ASSERT_EQUALS(solution.singleNumber({ 2, 2, 1, 4, 4, 5, 5 }), 1);
    ASSERT_EQUALS(solution.singleNumber({ 2, 2, 5, 4, 4, 5, 1 }), 1);
    ASSERT_EQUALS(solution.singleNumber({ 2, 2, 5, 4, 1, 5, 4 }), 1);
    ASSERT_EQUALS(solution.singleNumber({ 4, 1, 2, 1, 2 }), 4);
    ASSERT_EQUALS(solution.singleNumber({ 1 }), 1);
    return EXIT_SUCCESS;
}
