#include <stack>

#include "../Helpers.hpp"

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