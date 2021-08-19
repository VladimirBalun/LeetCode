#include <vector>
#include <unordered_map>

#include "../Helpers.hpp"

class Solution
{
public:
    std::vector<int> twoSum(const std::vector<int>& nums, int target)
    {
        std::unordered_map<int, size_t> table{};
        for (size_t i = 0u; i < nums.size(); ++i) {
            const auto it = table.find(target - nums[i]);
            if (it != end(table)) {
                return { static_cast<int>(it->second), static_cast<int>(i) };
            } else {
                table.emplace(nums[i], i);
            }
        }

        return {};
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        const std::vector<int> data{ 2, 7, 11, 15 };
        ASSERT_EQUALS(solution.twoSum(data, 9), (std::vector<int>{ 0, 1 }));
    }
    {
        const std::vector<int> data{ 3, 2, 4 };
        ASSERT_EQUALS(solution.twoSum(data, 6), (std::vector<int>{ 1, 2 }));
    }
    {
        const std::vector<int> data{ 3, 3 };
        ASSERT_EQUALS(solution.twoSum(data, 6), (std::vector<int>{ 0, 1 }));
    }
    return EXIT_SUCCESS;
}