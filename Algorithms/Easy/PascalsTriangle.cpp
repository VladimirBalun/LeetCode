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
    std::vector<vector<int>> generate(int numRows)
    {
        if (numRows <= 0) {
            return {};
        }

        std::vector<vector<int>> result;
        result.emplace_back(vector<int>{ 1 });
        for (int i = 0u; i < numRows - 1; ++i) {
            const vector<int>& prev_row = result.back();
            std::vector<int> current_row(prev_row.size() + 1u);
            for (size_t j = 0u; j < current_row.size(); ++j) {
                const int left = (j > 0) ? (prev_row[j - 1]) : (0);
                const int right = (j < current_row.size() - 1u) ? (prev_row[j]) : (0);
                current_row[j] = left + right;
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
