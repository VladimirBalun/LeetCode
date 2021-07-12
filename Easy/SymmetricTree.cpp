#include <iostream>

struct TreeNode
{
    int data = 0;
    std::unique_ptr<TreeNode> left = nullptr;
    std::unique_ptr<TreeNode> right = nullptr;
};

bool is_symmetric_tree(const std::unique_ptr<TreeNode>& root_tree_node)
{
    if (!root_tree_node) {
        return false;
    }

    std::function<bool(const std::unique_ptr<TreeNode>&, const std::unique_ptr<TreeNode>&)> is_symmetric_impl;
    is_symmetric_impl = [&is_symmetric_impl](const std::unique_ptr<TreeNode>& lhs, const std::unique_ptr<TreeNode>& rhs) {
        if ((!lhs) && (!rhs)) {
            return true;
        } else if ((!lhs) || (!rhs)) {
            return false;
        } else {
            return (lhs->data == rhs->data) &&
                (is_symmetric_impl(lhs->left, rhs->right)) &&
                (is_symmetric_impl(lhs->right, rhs->left));
        }
    };

    return is_symmetric_impl(root_tree_node, root_tree_node);
}

int main(int argc, char** argv)
{
    {
        std::unique_ptr<TreeNode> root(new TreeNode{10, nullptr, nullptr});
        std::cout << "Is symmetric: " << is_symmetric_tree(root) << std::endl;
    }
    {
        std::unique_ptr<TreeNode> left(new TreeNode{10, nullptr, nullptr});
        std::unique_ptr<TreeNode> right(new TreeNode{10, nullptr, nullptr});
        std::unique_ptr<TreeNode> root(new TreeNode{20, std::move(left), std::move(right)});
        std::cout << "Is symmetric: " << is_symmetric_tree(root) << std::endl;
    }
    {
        std::unique_ptr<TreeNode> right(new TreeNode{10, nullptr, nullptr});
        std::unique_ptr<TreeNode> root(new TreeNode{20, nullptr, std::move(right)});
        std::cout << "Is symmetric: " << is_symmetric_tree(root) << std::endl;
    }
    return EXIT_SUCCESS;
}