#include <iostream>

// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

// Example 1:
// Input: x = 123
// Output: 321

// Example 2:
// Input: x = -123
// Output: -321

// Example 3:
// Input: x = 120
// Output: 21

// Example 4:
// Input: x = 0
// Output: 0

class Solution 
{
public:
    int reverse(int x) 
	{
        int reversed_number = 0;
   
        while (x != 0) {
            const int number = x % 10;
            x /= 10;
            
            if (((std::numeric_limits<int>::max() / 10) < reversed_number) ||
                ((std::numeric_limits<int>::min() / 10) > reversed_number)) {
                return 0;
            } else {
                reversed_number = reversed_number * 10 + number;
            }
        }

        return reversed_number;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}
