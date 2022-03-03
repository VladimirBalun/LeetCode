#include "../Helpers.hpp"

// Given the root of a binary tree, return all root-to-leaf paths in any order.
// A leaf is a node with no children.

// Example 1:
// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]

// Example 2:
// Input: root = [1]
// Output: ["1"]

class Solution
{
public:
    std::vector<std::string> binaryTreePaths(TreeNode* root)
    {
        if (!root) {
            return std::vector<std::string>{};
        }

        std::vector<std::string> result;
        std::function<void(TreeNode*, std::string_view)> impl;
        impl = [&impl, result&] (TreeNode* node, std::string_view path)
        {
            if (!node->left && !node->right) {
                std::string new_path = path + std::to_string(node->val);
                result.push_back(std::move(new_path));
            } else {
                std::string new_path = path + std::to_string(node->val) + "->";
                if (node->left) {
                    impl(node->left, new_path);
                }
                if (node->right) {
                    impl(node->right, new_path);
                }         
            }
        };

        impl(root, "");
        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
