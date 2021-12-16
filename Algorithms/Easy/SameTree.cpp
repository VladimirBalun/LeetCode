#include "../Helpers.hpp"

// Given the roots of two binary trees p and q, write a function to check if they are the same or not.
// Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

// Example 1:
// Input: p = [1,2,3], q = [1,2,3]
// Output: true

// Example 2:
// Input: p = [1,2], q = [1,null,2]
// Output: false

// Example 3:
// Input: p = [1,2,1], q = [1,1,2]
// Output: false

class Solution
{
public:
    bool isSameTree(const TreeNode* p, const TreeNode* q)
    {
        if ((!p) && (!q)) {
            return true;
        } else if ((!p) || (!q)) {
            return false;
        } else {
            return (p->val == q->val) &&
                   (isSameTree(p->left, q->left)) &&
                   (isSameTree(p->right, q->right));
        }
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        TreeNode left{10, nullptr, nullptr};
        TreeNode right{10, nullptr, nullptr};
        ASSERT_EQUALS(solution.isSameTree(&left, &right), true);
    }
    {
        TreeNode left{20, nullptr, nullptr};
        TreeNode left_left_child{10, nullptr, nullptr};
        TreeNode left_right_child{10, nullptr, nullptr};
        left.left = &left_left_child;
        left.right = &left_right_child;
        TreeNode right{20, nullptr, nullptr};
        TreeNode right_left_child{10, nullptr, nullptr};
        TreeNode right_right_child{10, nullptr, nullptr};
        right.left = &right_left_child;
        right.right = &right_right_child;
        ASSERT_EQUALS(solution.isSameTree(&left, &right), true);
    }
    {
        TreeNode left{20, nullptr, nullptr};
        TreeNode left_right_child{10, nullptr, nullptr};
        left.right = &left_right_child;
        TreeNode right{20, nullptr, nullptr};
        TreeNode right_left_child{10, nullptr, nullptr};
        right.left = &right_left_child;
        ASSERT_EQUALS(solution.isSameTree(&left, &right), false);
    }
    return EXIT_SUCCESS;
}