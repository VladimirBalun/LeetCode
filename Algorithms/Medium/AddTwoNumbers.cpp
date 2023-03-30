#include "../Helpers.hpp"

// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:
// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:
// Input: l1 = [0], l2 = [0]
// Output: [0]

// Example 3:
// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* left, ListNode* right)
    {
        if (!left)
            return right;
        if (!right)
            return left;

        bool carry = false;
        ListNode* dummy = new ListNode(0);
        ListNode* iterator = dummy;

        while (left || right) {
            int left_value = 0;
            if (left) {
                left_value = left->val;
                left = left->next;
            }

            int right_value = 0;
            if (right) {
                right_value = right->val;
                right = right->next;
            }

            int value = left_value + right_value + carry;
            if (value >= 10) {
                value %= 10;
                carry = true;
            } else {
                carry = false;
            }

            iterator->next = new ListNode(0);
            iterator = iterator->next;
            iterator->val = value;
        }

        if (carry)
            iterator->next = new ListNode(1);

        return dummy->next;
    }
};