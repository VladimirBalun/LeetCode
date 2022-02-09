#include "../Helpers.hpp"

// Given the root of a binary tree, determine if it is a valid binary search tree (BST).
// A valid BST is defined as follows:
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:
// Input: root = [2,1,3]
// Output: true

// Example 2:
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

class Solution
{
public:
    bool isValidBST(TreeNode* root)
    {
        std::function<bool(TreeNode*, TreeNode*, TreeNode*)> impl;
        impl = [&impl] (TreeNode* node, TreeNode* max, TreeNode* min)
        {
            if (!node) {
                return true;
            } else if ((max && node->val >= max->val) || (min && node->val <= min->val)) {
                return false;
            } else {
                return impl(node->left, node, min) && impl(node->right, max, node);
            }
        };

        return impl(root, nullptr, nullptr);
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
