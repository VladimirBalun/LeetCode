#include "../Helpers.hpp"

class Solution
{
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target)
    {
        if (matrix.empty()) {
            return false;
        }

        const int rows_size = static_cast<int>(matrix.size());
        const int cols_size = static_cast<int>(matrix.front().size());

        int begin = 0;
        int end = rows_size * cols_size - 1;
        while (begin <= end) {
            const int middle = (begin + end) / 2;
            const int current = matrix[middle / cols_size][middle % cols_size];
            if (current < target) {
                begin = middle + 1;
            } else if (current > target) {
                end = middle - 1;
            } else {
                return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        const std::vector<std::vector<int>> data{
            { 1, 3, 5, 7}, { 10, 11, 16, 20 }, { 23, 30, 34, 60 }
        };
        ASSERT_EQUALS(solution.searchMatrix(data, 3), true);
    }
    {
        const std::vector<std::vector<int>> data{
            { 1, 3, 5, 7}, { 10, 11, 16, 20 }, { 23, 30, 34, 60 }
        };
        ASSERT_EQUALS(solution.searchMatrix(data, 13), false);
    }
    {
        const std::vector<std::vector<int>> data{
            { 1, 3, 5, 7 }, { 10, 11, 16, 20 }, { 23, 30, 34, 50 }
        };
        ASSERT_EQUALS(solution.searchMatrix(data, 11), true);
    }
    return EXIT_SUCCESS;
}
