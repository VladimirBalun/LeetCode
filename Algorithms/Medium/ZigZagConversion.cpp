#include "../Helpers.hpp"

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R

// And then read line by line: "PAHNAPLSIIGYIR"
// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);

// Example 1:
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:
// Input: s = "A", numRows = 1
// Output: "A"

class Solution {
public:
    std::string convert(const std::string& s, int numRows)
    {
        if (numRows == 1u) {
            return s;
        }
        
        std::string result;
        for (size_t row = 0u; row < numRows; ++row) {
            const int step = (numRows - 1) * 2;
            for (size_t i = row; i < s.size(); i += step) {
                result += s[i];
                if (row > 0 && row < numRows - 1u && i + step - 2 * row < s.size()) {
                    result += s[i + step - 2 * row];
                }
            }
        }

        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}