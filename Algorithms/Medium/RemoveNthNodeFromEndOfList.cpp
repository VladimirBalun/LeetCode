#include "../Helpers.hpp"

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Example 1:
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:
// Input: head = [1], n = 1
// Output: []

// Example 3:
// Input: head = [1,2], n = 1
// Output: [1]

class Solution
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        for (int i = 0; i < n; ++i) {
            fast = fast->next;
        }        

        if (!fast) {
            return head->next;
        }

        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
