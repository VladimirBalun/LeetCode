#include "../Helpers.hpp"

// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

// Example 1:
// Input: head = [1,1,2]
// Output: [1,2]

// Example 2:
// Input: head = [1,1,2,3,3]
// Output: [1,2,3]

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (!head) {
            return head;
        }

        ListNode* iterator = head;
        while (iterator && iterator->next) {
            if (iterator->val == iterator->next->val) {
                iterator->next = iterator->next->next;
            } else {
                iterator = iterator->next;
            }
        }

        return head;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
