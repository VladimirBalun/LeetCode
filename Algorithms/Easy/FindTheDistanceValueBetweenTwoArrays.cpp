#include "../Helpers.hpp"

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
    {
    	int result = 0;
        std::sort(begin(arr2), end(arr2));
        for (const int num : arr1) {
        	int left = -1;
        	int right = arr2.size();
        	while (right - left > 1) {
        		const int middle = left + (right - left) / 2;
        		if (arr2[middle] >= num) {
        			right = middle;
        		} else {
        			left = middle;
        		}
        	}

        	int min_d = std::numeric_limits<int>::max();
        	if (right > 0)
        		min_d = std::min(min_d, abs(num - arr2[right - 1]));
            if (right < arr2.size())
        		min_d = std::min(min_d, abs(num - arr2[right]));
        	if (min_d > d)
        		++result;
        }

        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}
