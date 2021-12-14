#include "../Helpers.hpp"

// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.
// Given a string s, return true if it is a palindrome, or false otherwise.

// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.

// Example 2:
// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.

// Example 3:
// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.

class Solution
{
public:
    bool isPalindrome(const std::string& s) 
	{
        if (s.size() <= 1u) {
            return true;
        }

        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while ((!std::isalnum(s[left])) && (left < right)) {
                ++left;
            }       
            while ((!std::isalnum(s[right])) && (left < right)) {
                --right;
            }
            
            if (std::tolower(s[left]) == std::tolower(s[right])) {
                ++left;
                --right;
            } else {
                return false;
            }
        }
        
        return true;
    }
};

int main(int argc, char** argv)
{
	
	return EXIT_SUCCESS;
}
