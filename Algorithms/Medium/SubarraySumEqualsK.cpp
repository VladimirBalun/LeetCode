#include "../Helpers.hpp"

// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
// A subarray is a contiguous non-empty sequence of elements within an array.

// Example 1:
// Input: nums = [1,1,1], k = 2
// Output: 2

// Example 2:
// Input: nums = [1,2,3], k = 3
// Output: 2

class Solution {
public:
    int subarraySum(vector<int>& nums, int k)
    {
        std::unordered_map<int, int> sums;
        sums.emplace(0, 1);

        int result = 0;
        int current_sum = 0;
        for (const int number: nums) {
            current_sum += number;

            const int diff = current_sum - k;
            result += sums[diff];
            sums[current_sum]++;
        }

        return result;
    }
};