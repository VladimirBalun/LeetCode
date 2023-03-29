#include "../Helpers.hpp"

// Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

// Example 1:
// Input: nums = [3,2,1]
// Output: 1
// Explanation:
// The first distinct maximum is 3.
// The second distinct maximum is 2.
// The third distinct maximum is 1.

// Example 2:
// Input: nums = [1,2]
// Output: 2
// Explanation:
// The first distinct maximum is 2.
// The second distinct maximum is 1.
// The third distinct maximum does not exist, so the maximum (2) is returned instead.

// Example 3:
// Input: nums = [2,2,3,1]
// Output: 1
// Explanation:
// The first distinct maximum is 3.
// The second distinct maximum is 2 (both 2's are counted together since they have the same value).
// The third distinct maximum is 1.

class Solution
{
public:
    int thirdMax(std::vector<int>& nums)
    {
        const int min = std::numeric_limits<int>::min();

        std::optional<int> first_max;
        std::optional<int> second_max;
        std::optional<int> third_max;

        for (const int num: nums) {
            if ((first_max.has_value() && num == first_max.value()) || 
                (second_max.has_value() && num == second_max.value()) || 
                (third_max.has_value() && num == third_max.value()))
                continue;

            if (!first_max.has_value() || num > first_max.value()) {
                third_max = second_max;
                second_max = first_max;
                first_max = num;
            } else if (!second_max.has_value() || num > second_max.value()) {
                third_max = second_max;
                second_max = num;
            } else if (!third_max.has_value() || num > third_max.value()) {
                third_max = num;
            }
        }

        if (!third_max.has_value())
            return first_max.value();
        else
            return third_max.value();
    }
};