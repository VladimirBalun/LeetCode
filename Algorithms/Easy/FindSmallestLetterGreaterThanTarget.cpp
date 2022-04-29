#include "../Helpers.hpp"

// Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.
// Note that the letters wrap around.
// For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.

// Example 1:
// Input: letters = ["c","f","j"], target = "a"
// Output: "c"

// Example 2:
// Input: letters = ["c","f","j"], target = "c"
// Output: "f"

// Example 3:
// Input: letters = ["c","f","j"], target = "d"
// Output: "f"

class Solution
{
public:
    char nextGreatestLetter(const std::vector<char>& letters, char target)
    {
        int left = -1;
        int right = letters.size();
        
        while (right - left > 1) {
            const int middle = left + (right - left) / 2;
            if (letters[middle] <= target) {
                left = middle;
            } else {
                right = middle;
            }
        }

        return right != letters.size() ? letters[right] : letters[0u];
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
