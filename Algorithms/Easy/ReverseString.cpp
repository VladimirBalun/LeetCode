#include "../Helpers.hpp"

// Write a function that reverses a string. The input string is given as an array of characters s.
// You must do this by modifying the input array in-place with O(1) extra memory.

// Example 1:
// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]

// Example 2:
// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]

class Solution 
{
public:
    void reverseString(vector<char>& s) 
	{
    	for (size_t i = 0u; i < s.size() / 2u; ++i) {
			std::swap(s[i], s[s.size() - i - 1u]);
		}    
    }
};

int main()
{
	return EXIT_SUCCESS;
}
