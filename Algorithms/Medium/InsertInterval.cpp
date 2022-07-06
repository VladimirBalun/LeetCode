#include "../Helpers.hpp"

// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.

// Example 1:
// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]

// Example 2:
// Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
// Output: [[1,2],[3,10],[12,16]]
// Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

class Solution
{
public:
    std::vector<std::vector<int>> insert(const std::vector<std::vector<int>>& intervals, std::vector<int> new_interval)
    {
        std::vector<std::vector<int>> result;
        for (size_t i = 0u; i < intervals.size(); ++i) {
            auto& current_interval = intervals[i];
            if (new_interval[1] < current_interval[0]) {
                result.push_back(new_interval);
                result.insert(end(result), begin(intervals) + i, end(intervals));
                return result;
            } else if (new_interval[0] > current_interval[1]) {
                result.push_back(current_interval);
            } else {
                new_interval[0] = std::min(current_interval[0], new_interval[0]); 
                new_interval[1] = std::max(current_interval[1], new_interval[1]);
            }
        }

        result.push_back(new_interval);
        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}