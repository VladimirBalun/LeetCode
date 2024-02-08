#include "../Helpers.hpp"

// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// Example 1:
// Input: head = [1,2,3,4]
// Output: [1,4,2,3]

// Example 2:
// Input: head = [1,2,3,4,5]
// Output: [1,5,2,4,3]

class Solution
{
public:
    void reorderList(ListNode* head)
    {
        if (!head || !head->next)
            return;

        ListNode* middle = find_middle(head);
        ListNode* reversed = reverse(middle->next);
        middle->next = nullptr;

        while (head && reversed) {
            ListNode* head_next = head->next;
            ListNode* reversed_next = reversed->next;

            head->next = reversed;
            reversed->next = head_next;

            head = head_next;
            reversed = reversed_next;
        }
    }

    ListNode* find_middle(ListNode* node)
    {
        ListNode* slow = node;
        ListNode* fast = node;
        while (fast && fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* node)
    {
        ListNode* reversed = nullptr;
        while (node) {
            ListNode* temp = node->next;
            node->next = reversed;
            reversed = node;
            node = temp;
        }

        return reversed;
    }
};