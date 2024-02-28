#include "../Helpers.hpp"

// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
// You must implement a solution with a linear runtime complexity and use only constant extra space.

// Example 1:
// Input: nums = [2,2,3,2]
// Output: 3

// Example 2:
// Input: nums = [0,1,0,1,0,1,99]
// Output: 99

class Solution
{
public:
    int singleNumber(const std::vector<int>& numbers)
    {
        std::array<int, 32> representation{ 0 };
        for (int number: numbers) {
            for (int i = 0; i < 32; ++i) {
                if (number & 1)
                    ++representation[i];

                number = number >> 1;
            }
        }

        int sigle_number = 0;
        for (int i = 0; i < 32; ++i) {
            if (representation[i] % 3 != 0)
                sigle_number += (1 << i);
        }

        return sigle_number;
    }
};