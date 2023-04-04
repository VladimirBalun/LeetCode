#include "../Helpers.hpp"

// Given a string date representing a Gregorian calendar date formatted as YYYY-MM-DD, return the day number of the year.

// Example 1:
// Input: date = "2019-01-09"
// Output: 9
// Explanation: Given date is the 9th day of the year in 2019.

// Example 2:
// Input: date = "2019-02-10"
// Output: 41

class Solution {
public:
    int parseNumber(std::string str)
    {
        int number = 0;
        for (int i = 0; i < str.size(); ++i)
            number = (number * 10) + (str[i] - '0');

        return number;
    }

    int dayOfYear(std::string date)
    {
        std::array<int, 13> months{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        const int year = parseNumber(std::string(begin(date), begin(date) + 4));
        const int month = parseNumber(std::string(begin(date) + 5, begin(date) + 7));
        const int day = parseNumber(std::string(begin(date) + 8, begin(date) + 10));
        const bool leap_year = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

        int days_number = 0;
        for (int i = 1; i < month; ++i) {
            if (i == 2 && leap_year)
                days_number += months[i] + 1;
            else
                days_number += months[i];
        }

        return days_number + day;
    }
};