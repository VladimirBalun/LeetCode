#include "../Helpers.hpp"

// Given the head of a singly linked list, return true if it is a palindrome.

// Example 1:
// Input: head = [1,2,2,1]
// Output: true

// Example 2:
// Input: head = [1,2]
// Output: false

class Solution
{
public:
    bool isPalindrome(ListNode* head)
    {
        if ((!head) || (!head->next)) {
            return true;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        while ((fast->next) && (fast->next->next)) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if (fast->next) {
            fast = fast->next;
        }

        ListNode* reversed = nullptr;
        ListNode* reversed_slow = slow->next;
        while (reversed_slow) {
            ListNode* temp = reversed_slow->next;
            reversed_slow->next = reversed;
            reversed = reversed_slow;
            reversed_slow = temp;
        }

        ListNode* l1 = head;
        ListNode* l2 = reversed;
        while (l1 && l2) {
            if (l1->val != l2->val) {
                return false;
            }
                
            l1 = l1->next;
            l2 = l2->next;
        }

        return true;
    }
};

int main(int argc, char** argv)
{
    return EIXT_SUCCESS;
}
