#include "../Helpers.hpp"

// Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.
// Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.
// The tests are generated such that there is exactly one solution. You may not use the same element twice.

// Example 1:
// Input: numbers = [2,7,11,15], target = 9
// Output: [1,2]
// Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

// Example 2:
// Input: numbers = [2,3,4], target = 6
// Output: [1,3]
// Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

// Example 3:
// Input: numbers = [-1,0], target = -1
// Output: [1,2]
// Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

class Solution
{
public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target)
    {
        std::vector<int> result{};
        if (numbers.size() < 2u) {
            return result;
        }

        int left = 0;
        int right = static_cast<int>(numbers.size() - 1u);
        while (left <= right) {
            const int sum = numbers[left] + numbers[right];
            if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                result.push_back(left + 1);
                result.push_back(right + 1);
                return result;
            }
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        const std::vector<int> data{ 2, 7, 11, 15 };
        ASSERT_EQUALS(solution.twoSum(data, 9), (std::vector<int>{ 1, 2 }));
    }
    {
        const std::vector<int> data{ 2, 3, 4 };
        ASSERT_EQUALS(solution.twoSum(data, 6), (std::vector<int>{ 1, 3 }));
    }
    {
        const std::vector<int> data{ -1, 0 };
        ASSERT_EQUALS(solution.twoSum(data, -1), (std::vector<int>{ 1, 2 }));
    }
    return EXIT_SUCCESS;
}