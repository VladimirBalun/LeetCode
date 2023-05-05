#include "../Helpers.hpp"

// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

// Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]

// Example 2:
// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.

class Solution
{
public:
    std::vector<int> intersection(std::vector<int> nums1, std::vector<int> nums2)
    {
        std::sort(begin(nums1), end(nums1));
        std::sort(begin(nums2), end(nums2));

        int left = 0;
        int right = 0;
        std::vector<int> result;
        while (left < nums1.size() && right < nums2.size()) {
            if (nums1[left] < nums2[right]) {
                ++left;
            } else if (nums1[left] > nums2[right]) {
                ++right;
            } else {
                result.push_back(nums1[left]);
                ++left;
                ++right;

                while (left < nums1.size() && 
                       right < nums2.size() && 
                       nums1[left - 1] == nums1[left] && 
                       nums2[right - 1] == nums2[right]) {
                    ++left;
                    ++right;
                }
            }
        }

        return result;
    }
};