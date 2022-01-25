#include "../Helpers.hpp"

// Given an integer numRows, return the first numRows of Pascal's triangle.
// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

// Example 1:
// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:
// Input: numRows = 1
// Output: [[1]]

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> result;
        result.push_back(std::vector<int>(1, 1));
        for (size_t i = 2u; i <= numRows; ++i) {
            const std::vector<int>& prev_row = result[i - 1];
            std::vector<int> current_row(i, 1);
            for (size_t i = 1u; i < current_row.size() - 1u) {
                current_row[i] = prev_row[i - 1] + prev_row[i];
            }
            result.push_back(std::move(current_row));
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
