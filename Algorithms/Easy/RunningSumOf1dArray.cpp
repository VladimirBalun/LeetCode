class Solution {
public:
	std::vector<int> runningSum(const std::vector<int>& nums)
	{
		std::vector<int> result;
		result.reserve(nums.size());
		result.push_back(nums.front());
		for (size_t i = 1u; i < nums.size(); ++i)
			result.push_back(nums[i] + result[i - 1]);

		return result;
	}
};
