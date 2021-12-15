#include "../Helpers.hpp"

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

// Example 2:
// Input: nums = [0,1]
// Output: [[0,1],[1,0]]

// Example 3:
// Input: nums = [1]
// Output: [[1]]     

class Solution
{
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        if (nums.size() <= 1u) {
            return { nums };
        }

        std::vector<std::vector<int>> result;
        std::function<void(std::vector<int>&, size_t)> impl;
        impl = [&impl, &result](std::vector<int>& nums, size_t begin)
        {
            if (begin >= nums.size()) {
                result.push_back(nums);
                return;
            }

            for (size_t i = begin; i < nums.size(); ++i) {
                swap(nums[begin], nums[i]);
                impl(nums, begin + 1);
                swap(nums[begin], nums[i]);
            }
        };

        impl(nums, 0u);
        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
