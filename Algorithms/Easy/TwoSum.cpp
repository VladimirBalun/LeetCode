#include "../Helpers.hpp"

// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.

// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].

// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]

// Example 3:
// Input: nums = [3,3], target = 6
// Output: [0,1]

class Solution
{
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target)
    {
        std::unordered_map<int, size_t> table{};
        for (size_t i = 0u; i < nums.size(); ++i) {
            const auto it = table.find(target - nums[i]);
            if (it != end(table)) {
                return { static_cast<int>(it->second), static_cast<int>(i) };
            } else {
                table.emplace(nums[i], i);
            }
        }

        return {};
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        const std::vector<int> data{ 2, 7, 11, 15 };
        ASSERT_EQUALS(solution.twoSum(data, 9), (std::vector<int>{ 0, 1 }));
    }
    {
        const std::vector<int> data{ 3, 2, 4 };
        ASSERT_EQUALS(solution.twoSum(data, 6), (std::vector<int>{ 1, 2 }));
    }
    {
        const std::vector<int> data{ 3, 3 };
        ASSERT_EQUALS(solution.twoSum(data, 6), (std::vector<int>{ 0, 1 }));
    }
    return EXIT_SUCCESS;
}