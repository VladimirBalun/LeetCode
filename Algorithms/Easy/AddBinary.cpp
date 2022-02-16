#include "../Helpers.hpp"

// Given two binary strings a and b, return their sum as a binary string.

// Example 1:
// Input: a = "11", b = "1"
// Output: "100"

// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"

class Solution
{
public:
    std::string addBinary(const std::string& a, const std::string& b)
    {
        std::string result;
        int left = a.size() - 1;
        int right = b.size() - 1;
        int carry = 0;

        while (left >= 0 || right >= 0) {
            int sum = carry;
            if (left >= 0) {
                sum += a[left--] - '0';  
            }
            if (right >= 0) {
                sum += b[right--] - '0';                
            }
            result += std::to_string(sum % 2);
            carry = sum / 2;
        }

        if (carry != 0) {
            result += '1';
        }

        std::reverse(begin(result), end(result));
        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
