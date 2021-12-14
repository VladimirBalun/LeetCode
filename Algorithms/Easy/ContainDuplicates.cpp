#include "../Helpers.hpp"

// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

// Example 1:
// Input: nums = [1,2,3,1]
// Output: true

// Example 2:
// Input: nums = [1,2,3,4]
// Output: false

// Example 3:
// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

class Solution
{
public:
    bool containsDuplicate(const vector<int>& nums)
    {
        std::unordered_set<int> duplicates;
        for (const int num : nums) {
            if (duplicates.count(num)) {
                return true;
            } else {
                duplicates.insert(num);
            }
        }
        return false;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
