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
        const size_t middle = s.size() / 2u;
        for (size_t i = 0u; i < middle; ++i) {
            std::swap(s[i], s[s.size() - 1 - i]);
        }  
    }
};

int main()
{
	return EXIT_SUCCESS;
}
