#include <iostream>
#include <vector>

using interval_t = std::pair<int, int>;

std::vector<interval_t> merge_intervals(std::vector<interval_t> intervals)
{
    std::vector<interval_t> merged_intervals{};
    if (intervals.size() < 2u) {
        return intervals;
    }

    std::sort(intervals.begin(), intervals.end());
    merged_intervals.push_back(intervals.front());
    for (size_t i = 1u; i < intervals.size(); ++i) {
        const auto& current = intervals.at(i);
        const auto& prev = merged_intervals.back();
        if (prev.second >= current.first) {
            merged_intervals.back().second = current.second;
        } else {
            merged_intervals.push_back(current);
        }
    }

    return merged_intervals;
}

int main(int argc, char** argv)
{
    {
        const std::vector<interval_t> intervals = { };
        const std::vector<interval_t> merged_intervals = merge_intervals(intervals);
        for (const auto& interval : merged_intervals) {
            std::cout << "[" << interval.first << ", " << interval.second << "] ";
        }
        std::cout << std::endl;
    }
    {
        const std::vector<interval_t> intervals = { {1, 4} };
        const std::vector<interval_t> merged_intervals = merge_intervals(intervals);
        for (const auto& interval : merged_intervals) {
            std::cout << "[" << interval.first << ", " << interval.second << "] ";
        }
        std::cout << std::endl;
    }
    {
        const std::vector<interval_t> intervals = { {1, 4}, {4, 10} };
        const std::vector<interval_t> merged_intervals = merge_intervals(intervals);
        for (const auto& interval : merged_intervals) {
            std::cout << "[" << interval.first << ", " << interval.second << "] ";
        }
        std::cout << std::endl;
    }
    {
        const std::vector<interval_t> intervals = { {1, 4}, {4, 7}, {6, 10 } };
        const std::vector<interval_t> merged_intervals = merge_intervals(intervals);
        for (const auto& interval : merged_intervals) {
            std::cout << "[" << interval.first << ", " << interval.second << "] ";
        }
        std::cout << std::endl;
    }
    {
        const std::vector<interval_t> intervals = { {1, 3}, {2, 6}, {8, 10}, {15, 18} };
        const std::vector<interval_t> merged_intervals = merge_intervals(intervals);
        for (const auto& interval : merged_intervals) {
            std::cout << "[" << interval.first << ", " << interval.second << "] ";
        }
        std::cout << std::endl;
    }
    return EXIT_SUCCESS;
}