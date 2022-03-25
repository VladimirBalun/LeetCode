#include "../Helpers.hpp"

// Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
// You may return the answer in any order.

// Example 1:
// Input: n = 4, k = 2
// Output:
// [
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
// ]

// Example 2:
// Input: n = 1, k = 1
// Output: [[1]]

class Solution
{
public:
    std::vector<std::vector<int>> combine(int n, int k)
    {
        std::vector<int> combination;
        std::vector<std::vector<int>> result;

        std::function<void(int)> backtracking;
        backtracking = [&combination, k, n] (int number)
        {
            if (combination.size() == k)
                return result.push_back(combination);

            for (int i = number; i <= n; ++i) {
                combination.push_back(i);
                backtracking(i + 1);
                combination.pop_back();
            }
        };

        backtracking(1);
        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
