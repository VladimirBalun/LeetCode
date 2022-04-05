#include "../Helpers.hpp"

// Given an integer array nums, handle multiple queries of the following type:
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).

// Example 1:

// Input
// ["NumArray", "sumRange", "sumRange", "sumRange"]
// [[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
// Output
// [null, 1, -1, -3]

// Explanation
// NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
// numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
// numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
// numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3

class NumArray
{
public:
    NumArray(const std::vector<int>& nums)
        : m_prefix_sum(nums.size() + 1u)
    {
        m_prefix_sum[0u] = 0;
        for (size_t i = 0u; i < nums.size(); ++i) {
            m_prefix_sum[i + 1] = m_prefix_sum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right)
    {
        return m_prefix_sum[right + 1] - m_prefix_sum[left];
    }
private:
    std::vector<int> m_prefix_sum;
};


int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
