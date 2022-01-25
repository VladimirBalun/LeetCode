#include "../Helpers.hpp"

// Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:
// Input: rowIndex = 3
// Output: [1,3,3,1]

// Example 2:
// Input: rowIndex = 0
// Output: [1]

// Example 3:
// Input: rowIndex = 1
// Output: [1,1]

class Solution
{
public:
    std::vector<int> getRow(int row_index)
    {
        std::vector<int> row(1, 1);
        for (size_t i = 0u; i < row_index; ++i) {
        	row.push_back(1);
        	for (size_t i = row.size() - 2; i > 0; --i) {
        		row[i] += row[i - 1];
        	}
        }

        return row;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}