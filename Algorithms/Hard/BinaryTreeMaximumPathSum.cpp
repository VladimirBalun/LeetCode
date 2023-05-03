#include "../Helpers.hpp"

// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.
// The path sum of a path is the sum of the node's values in the path.
// Given the root of a binary tree, return the maximum path sum of any non-empty path.

// Example 1:
// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

// Example 2:
// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

class Solution
{
public:
    int maxPathSum(TreeNode* root)
    {
        int max_path_sum = root->val;
        std::function<int(TreeNode*)> impl;
        impl = [&impl, &max_path_sum](TreeNode* node)
        {
            if (!node)
                return 0;

            const int left = std::max(impl(node->left), 0);
            const int right = std::max(impl(node->right), 0);
            max_path_sum = std::max(max_path_sum, node->val + left + right);
            return node->val + std::max(left, right);
        };

        impl(root);
        return max_path_sum;
    }
};