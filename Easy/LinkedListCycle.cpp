#include <iostream>

#include "../Helpers.hpp"

struct ListNode
{
    int val;
    ListNode* next;
};

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
        ListNode* node_1 = nullptr;
        ASSERT_EQUALS(solution.hasCycle(node_1), false);
    }
    {
        ListNode node_1{1, nullptr};
        ASSERT_EQUALS(solution.hasCycle(&node_1), false);
    }
    {
        ListNode node_1{1, nullptr};
        ListNode node_2{ 2, nullptr};
        node_1.next = &node_2;
        node_2.next = &node_1;
        ASSERT_EQUALS(solution.hasCycle(&node_1), true);
    }
    {
        ListNode node_1{3, nullptr};
        ListNode node_2{ 2, nullptr};
        ListNode node_3{ 0, nullptr};
        node_1.next = &node_2;
        node_2.next = &node_3;
        node_3.next = &node_1;
        ASSERT_EQUALS(solution.hasCycle(&node_1), true);
    }
    {
        ListNode node_1{3, nullptr};
        ListNode node_2{ 2, nullptr};
        ListNode node_3{ 0, nullptr};
        ListNode node_4{ -4, nullptr};
        node_1.next = &node_2;
        node_2.next = &node_3;
        node_3.next = &node_4;
        node_4.next = &node_2;
        ASSERT_EQUALS(solution.hasCycle(&node_1), true);
    }
    return EXIT_SUCCESS;
}