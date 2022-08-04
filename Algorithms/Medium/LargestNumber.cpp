#include "../Helpers.hpp"

// Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
// Since the result may be very large, so you need to return a string instead of an integer.

// Example 1:
// Input: nums = [10,2]
// Output: "210"

// Example 2:
// Input: nums = [3,30,34,5,9]
// Output: "9534330"

class Solution
{
public:
    std::string largestNumber(const std::vector<int>& nums)
    {
        std::vector<std::string> str_nums(nums.size());
        for (size_t i = 0u; i < nums.size(); ++i) {
            str_nums[i] = std::to_string(nums[i]);
        }
        
        auto compare = [] (const std::string& lhs, const std::string& rhs)
        {
            return lhs + rhs > rhs + lhs;
        };
        
        std::sort(begin(str_nums), end(str_nums), compare);
                
        std::string result;
        for (auto&& str_num: str_nums) {
            result += std::move(str_num);
        } 
        
        size_t begin = 0u;
        const size_t end = result.size() - 1u;
        while (begin < end && result[begin] == '0') {
            ++begin;
        }
        
        return std::string(result.begin() + begin, result.end());
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}
