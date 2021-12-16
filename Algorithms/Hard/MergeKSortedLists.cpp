#include "../Helpers.hpp"

// You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
// Merge all the linked-lists into one sorted linked-list and return it.

// Example 1:
// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
// Explanation: The linked-lists are:
// [
//    1->4->5,
//    1->3->4,
//    2->6
// ]
// merging them into one sorted list:
// 1->1->2->3->4->4->5->6

// Example 2:
// Input: lists = []
// Output: []

// Example 3:
// Input: lists = [[]]
// Output: []

ListNode* merge_lists(const std::vector<ListNode*>& lists)
{
    static const auto comparator = [](const ListNode* lhs, const ListNode* rhs) {
        return lhs->val > rhs->val;
    };

    std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(comparator)> iterators(comparator);
    for (ListNode* iterator : lists) {
        if (iterator) {
            iterators.push(iterator);
        }
    }

    ListNode* sorted_list = nullptr;
    ListNode* sorted_list_iterator = nullptr;
    while (!iterators.empty()) {
        auto current_iterator = iterators.top();
        if (!sorted_list) {
            sorted_list_iterator = sorted_list = new ListNode{ current_iterator->val };
        } else {
            sorted_list_iterator->next = new ListNode{ current_iterator->val };
            sorted_list_iterator = sorted_list_iterator->next;
        }
        iterators.pop();
        if (current_iterator = current_iterator->next) {
            iterators.push(current_iterator);
        }
    }

    return sorted_list;
}

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
