#include "../Helpers.hpp"

// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1

class Solution
{
public:
    int search(const std::vector<int>& nums, int target)
    {
        if (nums.empty()) {
            return -1;
        }

        int begin = 0;
        int end = static_cast<int>(nums.size()) - 1;
        while (begin <= end) {
            const int middle = (begin + end) / 2;
            if (target == nums.at(middle)) {
                return middle;
            } else if (target < nums.at(middle)) {
                end = middle - 1;
            } else if (target > nums.at(middle)) {
                begin = middle + 1;
            }
        }

        return -1;
    }
};

int main(int argc, char** argv)
{
    Solution solution;

    ASSERT_EQUALS(solution.search({}, 10), -1);

    ASSERT_EQUALS(solution.search({ 5 }, 3), -1);
    ASSERT_EQUALS(solution.search({ 5 }, 5), 0);
    ASSERT_EQUALS(solution.search({ 5 }, 7), -1);

    ASSERT_EQUALS(solution.search({ 2, 5 }, 1), -1);
    ASSERT_EQUALS(solution.search({ 2, 5 }, 2), 0);
    ASSERT_EQUALS(solution.search({ 2, 5 }, 5), 1);

    ASSERT_EQUALS(solution.search({ 2, 5, 7 }, 0), -1);
    ASSERT_EQUALS(solution.search({ 2, 5, 7 }, 2), 0);
    ASSERT_EQUALS(solution.search({ 2, 5, 7 }, 5), 1);
    ASSERT_EQUALS(solution.search({ 2, 5, 7 }, 7), 2);
    ASSERT_EQUALS(solution.search({ 2, 5, 7 }, 9), -1);

    ASSERT_EQUALS(solution.search({ 1, 2, 3, 4, 5, 6, 7, 8 }, 0), -1);
    ASSERT_EQUALS(solution.search({ 1, 2, 3, 4, 5, 6, 7, 8 }, 1), 0);
    ASSERT_EQUALS(solution.search({ 1, 2, 3, 4, 5, 6, 7, 8 }, 2), 1);
    ASSERT_EQUALS(solution.search({ 1, 2, 3, 4, 5, 6, 7, 8 }, 3), 2);
    ASSERT_EQUALS(solution.search({ 1, 2, 3, 4, 5, 6, 7, 8 }, 4), 3);
    ASSERT_EQUALS(solution.search({ 1, 2, 3, 4, 5, 6, 7, 8 }, 5), 4);
    ASSERT_EQUALS(solution.search({ 1, 2, 3, 4, 5, 6, 7, 8 }, 10), -1);

    return EXIT_SUCCESS;
}
