#include "../Helpers.hpp"

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
// Notice that the solution set must not contain duplicate triplets.

// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]

// Example 2:
// Input: nums = []
// Output: []

// Example 3:
// Input: nums = [0]
// Output: []

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> numbers)
    {
        std::vector<std::vector<int>> result{};
        if (numbers.size() < 3u) {
            return result;
        }

        std::sort(numbers.begin(), numbers.end());
        for (size_t i = 0u; i < numbers.size() - 2u; ++i) {
            if ((i > 0u) && (numbers[i] == numbers[i - 1u])) {
                continue;
            }
            size_t left = i + 1u;
            size_t right = numbers.size() - 1u;
            while (left < right) {
                const int sum = numbers[i] + numbers[left] + numbers[right];
                if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                } else {
                    result.push_back({ numbers[i], numbers[left], numbers[right] });
                    do {
                        ++left;
                    } while ((left < right) && (numbers[left] == numbers[left - 1u]));
                }
            }
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}