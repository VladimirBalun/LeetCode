#include "../Helpers.hpp"

// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:
// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

// Example 2:
// Input: head = [-1,5,3,4,0]
// Output: [-1,0,3,4,5]

// Example 3:
// Input: head = []
// Output: []

class Solution
{
public:    
    ListNode* sortList(ListNode* head)
    {
        if (!head || !head->next)
            return head;
        
        auto middle = split_in_middle(head);
        auto lhs = sortList(head);
        auto rhs = sortList(middle);

        return merge(lhs, rhs);
    }
    
private:
    ListNode* split_in_middle(ListNode* node)
    {
        auto temp = node;
        auto slow = node;
        auto fast = node;
        
        while (fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        temp->next = nullptr;
        return slow;
    }
    
    ListNode* merge(ListNode* lhs, ListNode* rhs)
    {
        auto merged = new ListNode();
        auto iterator = merged;
        
        while (lhs && rhs) {
            if (lhs->val < rhs->val) {
                iterator->next = lhs;
                lhs = lhs->next;
            } else {
                iterator->next = rhs;
                rhs = rhs->next;
            }
            
            iterator = iterator->next;
        }
        
        if (lhs)
            iterator->next = lhs;
        
        if (rhs)
            iterator->next = rhs;
            
        return merged->next;
    }
};