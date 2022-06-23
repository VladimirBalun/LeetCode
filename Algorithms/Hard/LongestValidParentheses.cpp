#include "../Helpers.hpp"

// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

// Example 1:
// Input: s = "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()".

// Example 2:
// Input: s = ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()".

// Example 3:
// Input: s = ""
// Output: 0

class Solution {
public:
    template<typename It>
    int search(It start, It finish, std::function<bool(int, int)> comparator)
    {
        int left = 0;
        int right = 0;
        int max_length = 0;

        for (auto it = start; it != finish; ++it) {
            if (*it == '(') {
                ++left;
            } else {
                ++right;
            }
            
            if (left == right) {
                max_length = std::max(max_length, 2 * right);
            } else if (comparator(right, left)) {
                left = right = 0;
            }
        }
        
        return max_length;
    }
    
    int longestValidParentheses(string s)
    {
        if (s.empty()) {
            return 0;
        }
        
        return std::max(search(begin(s), end(s), std::greater_equal<int>{}), 
                        search(rbegin(s), rend(s), std::less<int>{}));
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}