#include "../Helpers.hpp"

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
// Return the max sliding window.

// Example 1:
// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
//[1  3  -1] -3  5  3  6  7       3
// 1 [3  -1  -3] 5  3  6  7       3
// 1  3 [-1  -3  5] 3  6  7       5
// 1  3  -1 [-3  5  3] 6  7       5
// 1  3  -1  -3 [5  3  6] 7       6
// 1  3  -1  -3  5 [3  6  7]      7

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]

class Solution
{
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
    {
        std::vector<int> result;
        std::deque<int> monotonic_queue;

        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (!monotonic_queue.empty() && nums[right] > monotonic_queue.back())
                monotonic_queue.pop_back();

            monotonic_queue.push_back(nums[right]);
            if (right >= k && nums[right - k] == monotonic_queue.front())
                    monotonic_queue.pop_front();

            if ((right + 1) >= k) {
                result.push_back(monotonic_queue.front());
                ++left;
            }
        }

        return result;
    }
};