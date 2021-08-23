#include <stack>

#include "../Helpers.hpp"

class Solution
{
public:
    std::vector<std::vector<int>> pathSum(const TreeNode* root, int target_sum)
    {
        std::vector<std::vector<int>> result{};
        if (!root) {
            return result;
        }

        int current_sum = 0;
        std::vector<int> path{};
        std::function<void(const TreeNode*)> dfs_impl;
        dfs_impl = [&dfs_impl, &result, &path, &current_sum, target_sum](const TreeNode* node) {
            current_sum += node->val;
            path.push_back(node->val);
            if ((!node->left) && (!node->right) && (target_sum == current_sum)) {
                result.push_back(path);
            } else {
                if (node->left) {
                    dfs_impl(node->left);
                }
                if (node->right) {
                    dfs_impl(node->right);
                }
            }
            current_sum -= node->val;
            path.pop_back();
        };

        dfs_impl(root);
        return result;
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        {
            TreeNode left{2, nullptr, nullptr};
            TreeNode right{3, nullptr, nullptr};
            TreeNode root{1, &left, &right};
            ASSERT_EQUALS(solution.pathSum(&root, 5), std::vector<std::vector<int>>{});
        }
    }
    {
        TreeNode left_left_right{2, nullptr, nullptr};
        TreeNode left_left{11, nullptr, &left_left_right};
        TreeNode left{4, &left_left, nullptr};
        TreeNode root{5, &left, nullptr};
        ASSERT_EQUALS(solution.pathSum(&root, 22), (std::vector<std::vector<int>>{ { 5, 4, 11, 2 } }));
    }
    {
        TreeNode left_left_right{2, nullptr, nullptr};
        TreeNode left_left{11, nullptr, &left_left_right};
        TreeNode left{4, &left_left, nullptr};
        TreeNode right_right_left{5, nullptr, nullptr};
        TreeNode right_right{4, &right_right_left, nullptr};
        TreeNode right{8, nullptr, &right_right};
        TreeNode root{5, &left, &right};
        ASSERT_EQUALS(solution.pathSum(&root, 22), (std::vector<std::vector<int>>{
            { 5, 4, 11, 2 }, { 5, 8, 4, 5} }));
    }
    return EXIT_SUCCESS;
}