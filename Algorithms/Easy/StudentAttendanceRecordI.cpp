#include "../Helpers.hpp"

// You are given a string s representing an attendance record for a student where each character signifies whether the student was absent, late, or present on that day. The record only contains the following three characters:

// 'A': Absent.
// 'L': Late.
// 'P': Present.
// The student is eligible for an attendance award if they meet both of the following criteria:

// The student was absent ('A') for strictly fewer than 2 days total.
// The student was never late ('L') for 3 or more consecutive days.
// Return true if the student is eligible for an attendance award, or false otherwise.

// Example 1:
// Input: s = "PPALLP"
// Output: true
// Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.

// Example 2:
// Input: s = "PPALLL"
// Output: false
// Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.

class Solution
{
public:
    bool checkRecord(std::string s)
    {
        int absent_count = 0;
        int late_sequence = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'A') {
                ++absent_count;
                late_sequence = 0;
                if (absent_count == 2)
                    return false;
            } else if (s[i] == 'L') {
                ++late_sequence;
                if (late_sequence == 3)
                    return false;
            } else {
                late_sequence = 0;
            }
        }

        return true;
    }
};