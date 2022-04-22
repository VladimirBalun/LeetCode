#include "../Helpers.hpp"

// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
// Return the decimal value of the number in the linked list.

// Example 1:
// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10

// Example 2:
// Input: head = [0]
// Output: 0

class Solution
{
public:
    int getDecimalValue(ListNode* head)
    {
        int number = head->val;
        head = head->next;

        while (head) {
            number = (number << 1) | head->val;
            head = head->next;
        }

        return number;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
