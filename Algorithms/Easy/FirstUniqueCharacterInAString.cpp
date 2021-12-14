#include "../Helpers.hpp"

// Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

// Example 1:
// Input: s = "leetcode"
// Output: 0

// Example 2:
// Input: s = "loveleetcode"
// Output: 2

// Example 3:
// Input: s = "aabb"
// Output: -1

class Solution 
{
public:
    int firstUniqChar(string s) 
	{
		constexpr size_t ALPHABET_SIZE = 'z' - 'a' + 1u;
    	std::array<int, ALPHABET_SIZE> symbols{};
	    for (const char sym : s) {
			const char index = sym - 'a';
			symbols[index] += 1u;	
		}
	
		for (size_t i = 0u; i < s.size(); ++i) {
			const char sym = s[i];
			const char index = sym - 'a';
			if (symbols[index] == 1) {
				return i;
			}
		}

		return -1;	
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}
