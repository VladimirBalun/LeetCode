#include "../Helpers.hpp"

// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

class Solution
{
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k)
    {
        std::unordered_map<int, int> frequencies;
        for (const auto num: nums)
            ++frequencies[num];
        
        std::vector<std::vector<int>> buckets(nums.size() + 1);
        for (auto iterator: frequencies)
            buckets[iterator.second].push_back(iterator.first);
        
        std::vector<int> result;
        for (ssize_t i = buckets.size() - 1; i >= 0 && k > 0; --i) {
            for (size_t j = 0; j < buckets[i].size() && k > 0; ++j) {
                result.push_back(buckets[i][j]);
                --k;
            }
        }
                
        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}