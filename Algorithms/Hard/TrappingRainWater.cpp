#include "../Helpers.hpp"

// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

// Example 1:
// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

// Example 2:
// Input: height = [4,2,0,3,2,5]
// Output: 9

class Solution
{
public:
    int trap(std::vector<int>& height)
    {
        size_t max_height_index = 0u;
        for (size_t i = 0u; i < height.size(); ++i) {
            if (height[max_height_index] < height[i]) {
                max_height_index = i;
            }
        }

        int water_area = 0;
        int current_height = 0;
        for (size_t i = 0u; i < max_height_index; ++i) {
            if (height[i] > current_height) {
                current_height = height[i];
            }

            water_area += current_height - height[i];
        }

        current_height = 0;
        for (size_t i = height.size() - 1u; i > max_height_index; --i) {
            if (height[i] > current_height) {
                current_height = height[i];
            }

            water_area += current_height - height[i];
        }

        return water_area;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
