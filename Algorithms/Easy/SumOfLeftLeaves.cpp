#include "../Helpers.hpp"

// Given the root of a binary tree, return the sum of all left leaves.
// A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

// Example 2:
// Input: root = [1]
// Output: 0

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        if (!root) {
            return 0;
        } else if (root->left && !root->left->left && !root->left->right) {
            return root->left->val + sumOfLeftLeaves(right);
        } else {
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
