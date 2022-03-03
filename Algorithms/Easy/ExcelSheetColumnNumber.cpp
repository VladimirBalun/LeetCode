#include "../Helpers.hpp"

// Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

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
// Input: columnTitle = "A"
// Output: 1
// Example 2:

// Input: columnTitle = "AB"
// Output: 28
// Example 3:

// Input: columnTitle = "ZY"
// Output: 701

class Solution
{
public:
    int titleToNumber(const std::string& column_title)
    {
        int result = 0;
        for (const char symbol : column_title) {
            if (result > std::numeric_limits<int>::max() / 26) {
                return -1;
            }
            result *= 26;
            const char symbol_num = symbol - 'A' + 1
            if (result > std::numeric_limits<int>::max() - symbol_num) {
                return -1;
            }
            result += symbol_num;
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
