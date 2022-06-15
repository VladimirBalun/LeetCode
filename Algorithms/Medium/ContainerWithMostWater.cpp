#include "../Helpers.hpp"

// You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
// Find two lines that together with the x-axis form a container, such that the container contains the most water.
// Return the maximum amount of water a container can store.
// Notice that you may not slant the container.

// Example 1:
// Input: height = [1,8,6,2,5,4,8,3,7]
// Output: 49
// Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

// Example 2:
// Input: height = [1,1]
// Output: 1

class Solution
{
public:
    int maxArea(const std::vector<int>& height)
    {
        size_t left = 0u;
        size_t right = height.size() - 1u;

        int max_area = 0;
        while (left < right) {
        	const int left_height = height[left];
        	const int right_height = height[right];
        	const int local_max_area = std::min(left_height, right_height) * (right - left);
        	max_area = std::max(max_area, local_max_area);

        	if (left_height <= right_height) {
        		++left;
        	} else {
        		--right;
        	}
        }

        return max_area;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}
