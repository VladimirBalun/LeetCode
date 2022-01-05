#include "../Helpers.hpp"

// Given the root of a binary tree, invert the tree, and return its root.

// Example 1:
// Input: root = [4,2,7,1,3,6,9]
// Output: [4,7,2,9,6,3,1]

// Example 2:
// Input: root = [2,1,3]
// Output: [2,3,1]

// Example 3:
// Input: root = []
// Output: []

class Solution
{
public:
    TreeNode* invertTree(TreeNode* root)
    {
        std::function<void(TreeNode*)> impl;
        impl = [] (TreeNode* node)
        {
            if (node) {
                TreeNode* left = node->left;
                TreeNode* right = node->right;
                node->left = right;
                node->right = left;

                impl(node->left);
                impl(node->right);
            }
        };

        impl(root);
        return root;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}