#include "../Helpers.hpp"

// You are given the root of a binary search tree (BST) and an integer val.
// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

// Example 1:
// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]

// Example 2:
// Input: root = [4,2,7,1,3], val = 5
// Output: []

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val)
    {
        TreeNode* node = root;
        while (node) {
            if (node->val < val) 
                node = node->right;
            else if (node->val > val)
                node = node->left;
            else 
                return node;
        }

        return nullptr;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
