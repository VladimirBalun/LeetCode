#include "../Helpers.hpp"

// There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).
// You are given the integer capacity and an array trips where trips[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.
// Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

// Example 1:
// Input: trips = [[2,1,5],[3,3,7]], capacity = 4
// Output: false

// Example 2:
// Input: trips = [[2,1,5],[3,3,7]], capacity = 5
// Output: true

class Solution
{
public:
    bool isOverlapping(const std::vector<int>& lhs, const std::vector<int>& rhs)
    {
        return std::max(lhs[0], rhs[0]) <= std::min(lhs[1], rhs[1]);
    }

    int findMinArrowShots(std::vector<std::vector<int>>& points)
    {
        if (points.empty())
            return 0;

        std::sort(begin(points), end(points));

        int arrows_number = 1;
        auto last_point = points[0];
        for (int i = 1; i < points.size(); ++i) {
            const auto& point = points[i];
            if (isOverlapping(last_point, point)) {
                last_point[0] = std::max(last_point[0], point[0]);
                last_point[1] = std::min(last_point[1], point[1]);
                continue;
            }

            last_point[0] = point[0];
            last_point[1] = point[1];
            ++arrows_number;
        }

        return arrows_number;
    }
};
