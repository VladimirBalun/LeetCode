#include "../Helpers.hpp"
    |  
// Given the root of a binary tree, return its maximum depth.
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: 3

// Example 2:
// Input: root = [1,null,2]
// Output: 2

// Example 3:
// Input: root = []
// Output: 0

// Example 4:
// Input: root = [0]
// Output: 1

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
	{
        std::function<int(TreeNode*)> impl;
        impl = [&impl](TreeNode* node) 
        {
            if (!node) {
                return 0;
            }

            const int left = impl(node->left) + 1;
            const int right = impl(node->right) + 1;
            return std::max(left, right);
        };

        
        return impl(root);
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}
