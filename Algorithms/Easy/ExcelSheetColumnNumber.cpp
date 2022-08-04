#include "../Helpers.hpp"

// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:
// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...

// Example 1:
// Input: columnNumber = 1
// Output: "A"

// Example 2:
// Input: columnNumber = 28
// Output: "AB"

// Example 3:
// Input: columnNumber = 701
// Output: "ZY"

class Solution {
public:
    std::string convertToTitle(int column_number)
    {
    	std::string result;
        while (column_number > 0) {
        	result.push_back((column_number - 1) % 26 + 'A');
        	column_number = (column_number - 1) / 26;
        }

        std::reverse(begin(result), end(result));
        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}