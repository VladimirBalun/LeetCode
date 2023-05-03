#include "../Helpers.hpp"

// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        std::stack<std::pair<int, int>> stack;;
        std::vector<int> result(temperatures.size());
        for (int day = temperatures.size() - 1; day >= 0; --day) {
            const int current_temperature = temperatures[day];
            while (!stack.empty() && stack.top().first <= current_temperature)
                stack.pop();

            if (!stack.empty()) {
                const auto warmer_day = stack.top().second;
                result[day] = warmer_day - day;
            } else {
                result[day] = 0;
            }   

            stack.emplace(current_temperature, day);
        }

        return result;
    }
};