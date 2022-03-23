#include "../Helpers.hpp"

// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

// Example 1:
// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:
// Input: list1 = [], list2 = []
// Output: []

// Example 3:
// Input: list1 = [], list2 = [0]
// Output: [0]

class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1)
            return l2;
        
        if (!l2)
            return l1;
        
        ListNode* it = nullptr;
        ListNode* result = nullptr;
        if (l1->val <= l2->val) {
            result = it = l1;
            l1 = l1->next;
        } else {
            result = it = l2;
            l2 = l2->next;
        }

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                it->next = l1;
                l1 = l1->next;
            } else {
                it->next = l2;
                l2 = l2->next;
            }
            it = it->next;
        }

        if (l1)
            it->next = l1;
        else if (l2)
            it->next = l2;
        
        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
