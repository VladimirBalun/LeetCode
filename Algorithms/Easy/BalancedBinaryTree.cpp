#include "../Helpers.hpp"

// Given a binary tree, determine if it is height-balanced.
// For this problem, a height-balanced binary tree is defined as:
// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: true

// Example 2:
// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false

// Example 3:
// Input: root = []
// Output: true

class Solution
{
public:
    bool isBalanced(const TreeNode* root)
    {
        if (!root) {
            return true;
        }

        std::function<int(const TreeNode*)> height;
        height = [&height](const TreeNode* node) {
            if (!node) {
                return 0;
            }

            const int left_height = height(node->left);
            const int right_height = height(node->right);
            const int difference = std::abs(left_height - right_height);
            if ((difference <= 1) && (left_height != -1) && (right_height != -1)) {
                return 1 + std::max(left_height, right_height);
            } else {
                return -1;
            }
        };

        return (height(root) != -1);
    }
};

int main(int argc, char** argv)
{
    Solution solution;
    {
        TreeNode root{10, nullptr, nullptr};
        ASSERT_EQUALS(solution.isBalanced(&root), true);
    }
    {
        TreeNode left{10, nullptr, nullptr};
        TreeNode right{10, nullptr, nullptr};
        TreeNode root{20, &left, &right};
        ASSERT_EQUALS(solution.isBalanced(&root), true);
    }
    {
        TreeNode right{10, nullptr, nullptr};
        TreeNode root{20, nullptr, &right};
        ASSERT_EQUALS(solution.isBalanced(&root), true);
    }
    {
        TreeNode right_right{10, nullptr, nullptr};
        TreeNode right{10, nullptr, &right_right};
        TreeNode root{20, nullptr, &right};
        ASSERT_EQUALS(solution.isBalanced(&root), false);
    }
    {
        TreeNode right_right_right{30, nullptr, nullptr};
        TreeNode right_right{30, nullptr, &right_right_right};
        TreeNode right{30, nullptr, &right_right};
        TreeNode left_left_left{10, nullptr, nullptr};
        TreeNode left_left{10, &left_left_left, nullptr};
        TreeNode left{10,  &left_left, nullptr};
        TreeNode root{20, &left, &right};
        ASSERT_EQUALS(solution.isBalanced(&root), false);
    }
    return EXIT_SUCCESS;
}