#include "../Helpers.hpp"

class Solution
{
public:
    bool isSymmetric(TreeNode* root)
    {
        if (!root) {
            return false;
        }

        std::function<bool(const TreeNode*, const TreeNode*)> is_symmetric_impl;
        is_symmetric_impl = [&is_symmetric_impl](const TreeNode* lhs, const TreeNode* rhs) {
            if ((!lhs) && (!rhs)) {
                return true;
            } else if ((!lhs) || (!rhs)) {
                return false;
            } else {
                return (lhs->val == rhs->val) &&
                       (is_symmetric_impl(lhs->left, rhs->right)) &&
                       (is_symmetric_impl(lhs->right, rhs->left));
            }
        };

        return is_symmetric_impl(root, root);
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        TreeNode root{10, nullptr, nullptr};
        ASSERT_EQUALS(solution.isSymmetric(&root), true);
    }
    {
        TreeNode left{10, nullptr, nullptr};
        TreeNode right{10, nullptr, nullptr};
        TreeNode root{20, &left, &right};
        ASSERT_EQUALS(solution.isSymmetric(&root), true);
    }
    {
        TreeNode right{10, nullptr, nullptr};
        TreeNode root{20, nullptr, &right};
        ASSERT_EQUALS(solution.isSymmetric(&root), false);
    }
    return EXIT_SUCCESS;
}