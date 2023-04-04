#include "../Helpers.hpp"

// Given a date, return the corresponding day of the week for that date.
// The input is given as three integers representing the day, month and year respectively.
// Return the answer as one of the following values {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.

// Example 1:
// Input: day = 31, month = 8, year = 2019
// Output: "Saturday"

// Example 2:
// Input: day = 18, month = 7, year = 1999
// Output: "Sunday"

// Example 3:
// Input: day = 15, month = 8, year = 1993
// Output: "Sunday"

class Solution
{
public:
    std::string dayOfTheWeek(int day, int month, int year)
    {
        int days_number = 4;
        for (int i = 1971; i < year; ++i) {
            if ((i % 400 == 0) || (i % 4 == 0 && i % 100 != 0))
                days_number += 366;
            else
                days_number += 365;
        }

        std::array<int, 13> months{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        const bool leap_year = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

        for (int i = 1; i < month; ++i) {
            if (i == 2 && leap_year)
                days_number += months[i] + 1;
            else
                days_number += months[i];
        }        

        std::array<std::string, 7> days{
            "Sunday", "Monday", "Tuesday", "Wednesday", 
            "Thursday", "Friday", "Saturday"
        };

        days_number += day;
        return days[days_number % 7];
    }
};