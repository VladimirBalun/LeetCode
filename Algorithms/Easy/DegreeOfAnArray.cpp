#include "../Helpers.hpp"

// Given a non-empty array of non-negative integers nums, the degree of this array is defined as the maximum frequency of any one of its elements.
// Your task is to find the smallest possible length of a (contiguous) subarray of nums, that has the same degree as nums.

// Example 1:
// Input: nums = [1,2,2,3,1]
// Output: 2
// Explanation: 
// The input array has a degree of 2 because both elements 1 and 2 appear twice.
// Of the subarrays that have the same degree:
// [1, 2, 2, 3, 1], [1, 2, 2, 3], [2, 2, 3, 1], [1, 2, 2], [2, 2, 3], [2, 2]
// The shortest length is 2. So return 2.

// Example 2:
// Input: nums = [1,2,2,3,1,4,2]
// Output: 6
// Explanation: 
// The degree is 3 because the element 2 is repeated 3 times.
// So [2,2,3,1,4,2] is the shortest subarray, therefore returning 6.

class Solution
{
public:
    int findShortestSubArray(std::vector<int>& nums)
    {
        int min_length = 0;
        int max_frequency = 0;
        std::unordered_map<int, int> frequencies;
        std::unordered_map<int, int> first_seens;
        for (int i = 0; i < nums.size(); ++i) {
            const int num = nums[i];
            if (first_seens.count(num) == 0)
                first_seens.emplace(num, i);

            const int frequency = ++frequencies[num];
            if (frequency > max_frequency) {
                max_frequency = frequency;
                min_length = i - first_seens[num] + 1;
            } else if (frequency == max_frequency) {
                min_length = std::min(min_length, i - first_seens[num] + 1);
            }
        }

        return min_length;
    }
};