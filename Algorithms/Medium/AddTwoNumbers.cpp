#include "../Helpers.hpp"

class Solution
{
public:
    ListNode* addTwoNumbers(const ListNode* l1, const ListNode* l2)
    {
        bool carry = false;
        ListNode* result = nullptr;
        ListNode* iterator = nullptr;
        while ((l1) || (l2)) {
            int left = 0;
            int right = 0;

            if (l1) {
                left = l1->val;
                l1 = l1->next;
            }
            if (l2) {
                right = l2->val;
                l2 = l2->next;
            }

            const int new_value = left + right + carry;
            const int new_node_value = (carry = (new_value >= 10)) ? (new_value - 10) : (new_value);
            auto new_node = new ListNode{ new_node_value, nullptr };
            if (!iterator) {
                result = iterator = new_node;
            } else {
                iterator->next = new_node;
                iterator = iterator->next;
            }
        }

        if (carry) {
            iterator->next = new ListNode{ 1, nullptr };
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        ListNode* list_1 = details::make_list({ 2 });
        ListNode* list_2 = details::make_list({ 5 });
        ListNode* expected = details::make_list({ 7 });
        ListNode* result = solution.addTwoNumbers(list_1, list_2);
        ASSERT_EQUALS(result, expected);
        details::delete_list(result);
        details::delete_list(expected);
        details::delete_list(list_2);
        details::delete_list(list_1);
    }
    {
        ListNode* list_1 = details::make_list({ 0, 3 });
        ListNode* list_2 = details::make_list({ 5 });
        ListNode* expected = details::make_list({ 5, 3 });
        ListNode* result = solution.addTwoNumbers(list_1, list_2);
        ASSERT_EQUALS(result, expected);
        details::delete_list(result);
        details::delete_list(expected);
        details::delete_list(list_2);
        details::delete_list(list_1);
    }
    {
        ListNode* list_1 = details::make_list({ 7 });
        ListNode* list_2 = details::make_list({ 5 });
        ListNode* expected = details::make_list({ 2, 1 });
        ListNode* result = solution.addTwoNumbers(list_1, list_2);
        ASSERT_EQUALS(result, expected);
        details::delete_list(result);
        details::delete_list(expected);
        details::delete_list(list_2);
        details::delete_list(list_1);
    }
    {
        ListNode* list_1 = details::make_list({ 2, 4, 3 });
        ListNode* list_2 = details::make_list({ 5, 6, 4 });
        ListNode* expected = details::make_list({ 7, 0, 8 });
        ListNode* result = solution.addTwoNumbers(list_1, list_2);
        ASSERT_EQUALS(result, expected);
        details::delete_list(result);
        details::delete_list(expected);
        details::delete_list(list_2);
        details::delete_list(list_1);
    }
    return EXIT_SUCCESS;
}