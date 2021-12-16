#include "../Helpers.hpp"

// Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
// A leaf is a node with no children.

// Example 1:
// Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
// Output: true
// Explanation: The root-to-leaf path with the target sum is shown.

// Example 2:
// Input: root = [1,2,3], targetSum = 5
// Output: false
// Explanation: There two root-to-leaf paths in the tree:
// (1 --> 2): The sum is 3.
// (1 --> 3): The sum is 4.
// There is no root-to-leaf path with sum = 5.

// Example 3:
// Input: root = [], targetSum = 0
// Output: false
// Explanation: Since the tree is empty, there are no root-to-leaf paths.

class Solution
{
public:
    bool hasPathSum(const TreeNode* root, int target_sum)
    {
        if (!root) {
            return false;
        }

        std::stack<int> sum_stack;
        std::stack<const TreeNode*> node_stack;

        node_stack.push(root);
        sum_stack.push(target_sum - root->val);
        while (!node_stack.empty()) {
            const int current_sum = sum_stack.top();
            const TreeNode* current_node = node_stack.top();
            sum_stack.pop();
            node_stack.pop();
            if ((!current_node->left) && (!current_node->right) && (current_sum == 0)) {
                return true;
            }
            if (current_node->left) {
                node_stack.push(current_node->left);
                sum_stack.push(current_sum - current_node->left->val);
            }
            if (current_node->right) {
                node_stack.push(current_node->right);
                sum_stack.push(current_sum - current_node->right->val);
            }
        }

        return false;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        TreeNode left{2, nullptr, nullptr};
        TreeNode root{1, &left, nullptr};
        ASSERT_EQUALS(solution.hasPathSum(&root, 1), false);
    }
    {
        TreeNode left{2, nullptr, nullptr};
        TreeNode right{3, nullptr, nullptr};
        TreeNode root{1, &left, &right};
        ASSERT_EQUALS(solution.hasPathSum(&root, 5), false);
    }
    {
        TreeNode left{2, nullptr, nullptr};
        TreeNode right{3, nullptr, nullptr};
        TreeNode root{1, &left, &right};
        ASSERT_EQUALS(solution.hasPathSum(&root, 4), true);
    }
    {
        TreeNode left_left_right{2, nullptr, nullptr};
        TreeNode left_left{11, nullptr, &left_left_right};
        TreeNode left{4, &left_left, nullptr};
        TreeNode right{8, nullptr, nullptr};
        TreeNode root{5, &left, &right};
        ASSERT_EQUALS(solution.hasPathSum(&root, 22), true);
    }
    return EXIT_SUCCESS;
}