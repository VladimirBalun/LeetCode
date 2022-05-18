#include "../Helpers.hpp"

// Given an array arr of positive integers sorted in a strictly increasing order, and an integer k.
// Find the kth positive integer that is missing from this array.

// Example 1:
// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

// Example 2:
// Input: arr = [1,2,3,4], k = 2
// Output: 6
// Explanation: The missing positive integers are [5,6,7,...]. The 2nd missing positive integer is 6.

class Solution {
public:
    int findKthPositive(const std::vector<int>& arr, int k)
    {
    	if (arr[0] > k) {
    		return k;
    	}

        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
        	const int middle = left + (right - left) / 2;
        	if (arr[middle] - (middle + 1) < k) {
        		left = middle + 1;
        	} else {
        		right = middle - 1;
        	}
        }

        return left + k;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}