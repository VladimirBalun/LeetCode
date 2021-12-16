#include "../Helpers.hpp"

// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.
// Return true if there is a cycle in the linked list. Otherwise, return false.

// Example 1:
// Input: head = [3,2,0,-4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

// Example 2:
// Input: head = [1,2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

// Example 3:
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.

class Solution
{
public:
    bool hasCycle(const ListNode* head)
    {
        if (!head || !head->next) {
            return false;
        }

        const ListNode* first = head;
        const ListNode* second = head->next;
        while ((second) && (second->next)) {
            if (first == second) {
                return true;
            }

            first = first->next;
            second = second->next->next;
        }

        return false;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        ASSERT_EQUALS(solution.hasCycle(nullptr), false);
    }
    {
        ListNode* list = details::make_linked_list_with_cycle({ 1 }, 0);
        ASSERT_EQUALS(solution.hasCycle(list), false);
        details::delete_list_with_cycle(list);
    }
    {
        ListNode* list = details::make_linked_list_with_cycle({ 1, 2 }, 1);
        ASSERT_EQUALS(solution.hasCycle(list), true);
        details::delete_list_with_cycle(list);
    }
    {
        ListNode* list = details::make_linked_list_with_cycle({ 3, 2, 0 }, 3);
        ASSERT_EQUALS(solution.hasCycle(list), true);
        details::delete_list_with_cycle(list);
    }
    {
        ListNode* list = details::make_linked_list_with_cycle({ 3, 2, 0, -4 }, 2);
        ASSERT_EQUALS(solution.hasCycle(list), true);
        details::delete_list_with_cycle(list);
    }
    return EXIT_SUCCESS;
}