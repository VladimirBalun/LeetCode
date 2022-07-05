#include "../Helpers.hpp"

// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

// Example 1:
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

// Example 2:
// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.

class Solution
{
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
    {
        if (intervals.size() == 1u)
            return intervals;
  
        std::sort(begin(intervals), end(intervals));
        std::vector<std::vector<int>> result;
        result.push_back(intervals[0]);
        
        for (size_t i = 1u; i < intervals.size(); ++i) {
            auto& next = intervals[i];
            auto& current = result[result.size() - 1u];
            if (next[0] <= current[1]) {
                current[1] = std::max(next[1], current[1]);
            } else {
                result.push_back(next);
            }
        }
        
        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}