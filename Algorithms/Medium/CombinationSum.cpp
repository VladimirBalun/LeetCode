#include "../Helpers.hpp"

// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
// It is guaranteed that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

// Example 1:
// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
// Explanation:
// 2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
// 7 is a candidate, and 7 = 7.
// These are the only two combinations.

// Example 2:
// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]

// Example 3:
// Input: candidates = [2], target = 1
// Output: []

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(const std::vector<int>& candidates, int target)
    {
        std::vector<int> combination;
        std::vector<std::vector<int>> result;

        std::function<void(size_t i, int)> backtracking;
        backtracking = [&backtracking, &candidates, &result, &combination, target] (size_t index, int candidate)
        {
            if (index >= candidates.size() || candidate > target)
                return;

            if (candidate == target)
                return result.push_back(combination);

            
            combination.push_back(candidates[index]);
            backtracking(index, candidate + candidates[index]);
            combination.pop_back();
            backtracking(index + 1, candidate);
        };

        backtracking(0u, 0);
        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}
