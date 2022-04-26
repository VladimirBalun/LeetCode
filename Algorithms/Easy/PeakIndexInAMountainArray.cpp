#include "../Helpers.hpp"

// Let's call an array arr a mountain if the following properties hold:

// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... arr[i-1] < arr[i]
// arr[i] > arr[i+1] > ... > arr[arr.length - 1]
// Given an integer array arr that is guaranteed to be a mountain, return any i such that arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1].

// Example 1:
// Input: arr = [0,1,0]
// Output: 1

// Example 2:
// Input: arr = [0,2,1,0]
// Output: 1

// Example 3:
// Input: arr = [0,10,5,2]
// Output: 1

class Solution
{
public:
    int peakIndexInMountainArray(const std::vector<int>& arr)
    {
        int left = 0;
        int right = arr.size() - 1;

        while (left != right) {
            const int m1 = left + (right - left) / 3;
            const int m2 = right - (right - left) / 3;
            if (arr[m2] > arr[m1]) {
                left = m1 + 1;
            } else {
                right = m2 - 1;
            }
        }

        return left;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
