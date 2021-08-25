#include "../Helpers.hpp"

class Solution
{
public:
    std::vector<int> twoSum(const std::vector<int>& numbers, int target)
    {
        std::vector<int> result{};
        if (numbers.size() < 2u) {
            return result;
        }

        int left = 0;
        int right = static_cast<int>(numbers.size() - 1u);
        while (left <= right) {
            const int sum = numbers[left] + numbers[right];
            if (sum > target) {
                --right;
            } else if (sum < target) {
                ++left;
            } else {
                result.push_back(left + 1);
                result.push_back(right + 1);
                return result;
            }
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        const std::vector<int> data{ 2, 7, 11, 15 };
        ASSERT_EQUALS(solution.twoSum(data, 9), (std::vector<int>{ 1, 2 }));
    }
    {
        const std::vector<int> data{ 2, 3, 4 };
        ASSERT_EQUALS(solution.twoSum(data, 6), (std::vector<int>{ 1, 3 }));
    }
    {
        const std::vector<int> data{ -1, 0 };
        ASSERT_EQUALS(solution.twoSum(data, -1), (std::vector<int>{ 1, 2 }));
    }
    return EXIT_SUCCESS;
}