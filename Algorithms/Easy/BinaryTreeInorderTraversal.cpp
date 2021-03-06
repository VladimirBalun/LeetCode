#include "../Helpers.hpp"

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Example 1:
// Input: root = [1,null,2,3]
// Output: [1,3,2]

// Example 2:
// Input: root = []
// Output: []

// Example 3:
// Input: root = [1]
// Output: [1]

class Solution
{
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        std::function<void(TreeNode*)> impl;
        impl = [&impl, &result] (TreeNode* node)
        {
        	if (node->left) {
        		impl(node->left);
        	}

        	result.push_back(node->val);
        	if (node->right) {
        		impl(node->right);
        	}
        };

        if (root) {
        	impl(root);
        }

        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}