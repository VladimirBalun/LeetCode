class Solution {
public:
	int finalValueAfterOperations(const std::vector<string>& operations)
	{
		int result = 0;
		for (const auto& operation: operations) {
			if (operation.front() == '+' || operation.back() == '+')
				++result;
			else
				--result;
		}

		return result;
	}
};