#include "../Helpers.hpp"

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        if (nums.size() < 4u) {
            return {};
        }
        
    	std::sort(begin(nums), end(nums));
    	std::vector<std::vector<int>> result;
    	for (size_t i = 0u; i < nums.size() - 3; ++i) {
    		if (i > 0 && nums[i] == nums[i - 1]) {
    			continue;
    		}

    		for (size_t j = i + 1; j < nums.size() - 2; ++j) {
    			if (j > i + 1 && nums[j] == nums[j - 1]) {
    				continue;
    			}

    			size_t left = j + 1;
    			size_t right = nums.size() - 1u;
    			const long long temp_sum = nums[i] + nums[j];
    			while (left < right) {
    				const long long sum = temp_sum + nums[left] + nums[right];
    				if (sum > target) {
    					--right;
    				} else if (sum < target) {
    					++left;
    				} else {
    					result.push_back({ nums[i], nums[j], nums[left], nums[right] });
    					++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1]) {
                            ++left;
                        }
    				}
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