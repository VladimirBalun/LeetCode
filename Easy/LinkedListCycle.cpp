#include <iostream>

#include "../Helpers.hpp"

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