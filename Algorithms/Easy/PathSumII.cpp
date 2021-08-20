#include "../Helpers.hpp"

class Solution
{
public:
    bool hasPathSum(TreeNode* root, int target_sum)
    {
        bool has_path_sum = false;
        std::function<void(TreeNode*, int&)> dfs_impl;
        dfs_impl = [&dfs_impl, &has_path_sum, target_sum] (TreeNode* node, int& current_sum) {
            if ((!node) || (has_path_sum)) {
                return;
            }

            current_sum += node->val;
            if (current_sum == target_sum) {
                has_path_sum = true;
                return;
            }

            dfs_impl(node->left, current_sum);
            dfs_impl(node->right, current_sum);
            current_sum -= node->val;
        };

        int current_sum = 0;
        return dfs_impl(root, current_sum);
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}