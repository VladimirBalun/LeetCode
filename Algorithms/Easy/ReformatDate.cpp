#include "../Helpers.hpp"

// Given a date string in the form Day Month Year, where:
// Day is in the set {"1st", "2nd", "3rd", "4th", ..., "30th", "31st"}.
// Month is in the set {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"}.
// Year is in the range [1900, 2100].
// Convert the date string to the format YYYY-MM-DD, where:

// YYYY denotes the 4 digit year.
// MM denotes the 2 digit month.
// DD denotes the 2 digit day.

// Example 1:
// Input: date = "20th Oct 2052"
// Output: "2052-10-20"

// Example 2:
// Input: date = "6th Jun 1933"
// Output: "1933-06-06"

// Example 3:
// Input: date = "26th May 1960"
// Output: "1960-05-26"

class Solution
{
public:
    int parseNumber(std::string str)
    {
        int number = 0;
        for (int i = 0; i < str.size(); ++i)
            number = (number * 10) + (str[i] - '0');

        return number;
    }

    std::string reformatDate(std::string date)
    {
        const int space_size = 1;
        const int month_size = 3;
        const int number_order_size = 2;

        std::unordered_map<std::string, int> months{
            {"Jan", 1}, {"Feb", 2}, {"Mar", 3}, {"Apr", 4}, {"May", 5}, {"Jun", 6}, 
            {"Jul", 7}, {"Aug", 8}, {"Sep", 9}, {"Oct", 10}, {"Nov", 11}, {"Dec", 12}
        };

        int idx = 0;
        while (std::isdigit(date[idx]))
            ++idx;

        const std::string day_str(begin(date), begin(date) + idx);
        const int day = parseNumber(day_str);
        idx += space_size + number_order_size;

        const std::string month_str(begin(date) + idx, begin(date) + idx + month_size);
        const int month = months[month_str];
        idx += month_size + space_size;

        const std::string year_str(begin(date) + idx, end(date));
        const int year = parseNumber(year_str);

        std::string result = std::to_string(year) + '-';
        if (month < 10)
            result += '0';
        result += std::to_string(month) + '-';
        if (day < 10)
            result += '0';  
        result += std::to_string(day);

        return result;
    }
};