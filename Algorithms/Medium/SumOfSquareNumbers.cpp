#include "../Helpers.hpp"

// Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

// Example 1:
// Input: c = 5
// Output: true
// Explanation: 1 * 1 + 2 * 2 = 5

// Example 2:
// Input: c = 3
// Output: false

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int left = 0;
        int right = std::sqrt(c);
        long long left_square = left * left;
        long long right_square = right * right;

        while (left <= right) {
        	const long long expression = left_square + right_square;
        	if (expression < c) {
        		++left;
        		left_square = left * left;
        	} else if (expression > c) {
        		--right;
        		right_square = right * right;
        	} else {
        		return true;
        	}
        }

        return false;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}
