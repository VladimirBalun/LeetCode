#include "../Helpers.hpp"

// Given an integer array nums of unique elements, return all possible 
// subsets (the power set).
// The solution set must not contain duplicate subsets. Return the solution in any order.

// Example 1:
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

// Example 2:
// Input: nums = [0]
// Output: [[],[0]]

class Solution
{
public:
    std::vector<std::vector<int>> subsets(const std::vector<int>& nums)
    {
        vector<vector<int>> result;
        std::vector<int> combination;
        result.push_back(combination);

        std::function<void(int)> backtracing;
        backtracing = [&backtracing, &result, &combination, &nums] (int index)
        {
            while (index < nums.size()) {
                combination.push_back(nums[index]);
                result.push_back(combination);

                backtracing(++index);
                combination.pop_back();
            }
        };

        backtracing(0);
        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}