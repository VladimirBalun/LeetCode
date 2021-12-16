#include "../Helpers.hpp"

// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1:
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2:
// Input: head = [1,2]
// Output: [2,1]

// Example 3:
// Input: head = []
// Output: []

class Solution
{
public:
    ListNode* reverseList(ListNode* head)
    {
        if (!head) {
            return nullptr;
        }

        ListNode* reversed = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = reversed;
            reversed = head;
            head = temp;
        }

        return reversed;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        ListNode* list = details::make_list({ 5 });
        ASSERT_EQUALS(solution.reverseList(list), details::make_list({ 5 }));
        details::delete_list(list);
    }
    {
        ListNode* list = details::make_list({ 5, 3 } );
        ASSERT_EQUALS(solution.reverseList(list), details::make_list({ 3, 5 }));
        details::delete_list(list);
    }
    {
        ListNode* list = details::make_list({ 5, 3, 1 } );
        ASSERT_EQUALS(solution.reverseList(list), details::make_list({ 1, 3, 5 }));
        details::delete_list(list);
    }
    return EXIT_SUCCESS;
}

