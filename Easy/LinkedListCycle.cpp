#include <iostream>

struct ListNode
{
    int value;
    ListNode* next;
};

bool has_cycle(ListNode* head)
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

int main(int argc, char** argv)
{
    {
        ListNode* node_1 = nullptr;
        std::cout << "Has cycle: " << has_cycle(node_1) << std::endl;
    }
    {
        ListNode node_1{1, nullptr};
        std::cout << "Has cycle: " << has_cycle(&node_1) << std::endl;
    }
    {
        ListNode node_1{1, nullptr};
        ListNode node_2{ 2, nullptr};
        node_1.next = &node_2;
        node_2.next = &node_1;
        std::cout << "Has cycle: " << has_cycle(&node_1) << std::endl;
    }
    {
        ListNode node_1{3, nullptr};
        ListNode node_2{ 2, nullptr};
        ListNode node_3{ 0, nullptr};
        node_1.next = &node_2;
        node_2.next = &node_3;
        node_3.next = &node_1;
        std::cout << "Has cycle: " << has_cycle(&node_1) << std::endl;
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
        std::cout << "Has cycle: " << has_cycle(&node_1) << std::endl;
    }
    return EXIT_SUCCESS;
}