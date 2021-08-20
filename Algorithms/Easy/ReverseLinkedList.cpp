#include "../Helpers.hpp"

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

