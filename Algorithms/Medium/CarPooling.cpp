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
    bool carPooling(std::vector<std::vector<int>>& trips, int capacity)
    {
        std::vector<std::vector<int>> events;
        for (const auto& values: trips) {
            const int passengers_number = values[0];
            const int start = values[1];
            const int end = values[2];

            events.push_back(std::vector<int>{ start, passengers_number });
            events.push_back(std::vector<int>{ end, -passengers_number });
        }

        int passengers = 0;
        std::sort(begin(events), end(events));
        for (const auto& event: events) {
            passengers += event[1];
            if (passengers > capacity)
                return false;
        }

        return true;
    }
};