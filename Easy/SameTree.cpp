#include <iostream>

struct TreeNode
{
    int data = 0;
    std::unique_ptr<TreeNode> left = nullptr;
    std::unique_ptr<TreeNode> right = nullptr;
};

bool is_same_tree(const std::unique_ptr<TreeNode>& left, const std::unique_ptr<TreeNode>& right)
{
    std::function<bool(const std::unique_ptr<TreeNode>&, const std::unique_ptr<TreeNode>&)> is_same_impl;
    is_same_impl = [&is_same_impl](const std::unique_ptr<TreeNode>& lhs, const std::unique_ptr<TreeNode>& rhs) {
        if ((!lhs) && (!rhs)) {
            return true;
        } else if ((!lhs) || (!rhs)) {
            return false;
        } else {
            return (lhs->data == rhs->data) &&
                (is_same_impl(lhs->left, rhs->left)) &&
                (is_same_impl(rhs->right, rhs->right));
        }
    };

    return is_same_impl(left, right);
}

int main(int argc, char** argv)
{
    {
        std::unique_ptr<TreeNode> left(new TreeNode{10, nullptr, nullptr});
        std::unique_ptr<TreeNode> right(new TreeNode{10, nullptr, nullptr});
        std::cout << "Is same: " << is_same_tree(left, right) << std::endl;
    }
    {
        std::unique_ptr<TreeNode> left;
        {
            std::unique_ptr<TreeNode> left_child(new TreeNode{10, nullptr, nullptr});
            std::unique_ptr<TreeNode> right_child(new TreeNode{10, nullptr, nullptr});
            left = std::unique_ptr<TreeNode>{new TreeNode{20, std::move(left_child), std::move(right_child)}};
        }
        std::unique_ptr<TreeNode> right;
        {
            std::unique_ptr<TreeNode> left_child(new TreeNode{10, nullptr, nullptr});
            std::unique_ptr<TreeNode> right_child(new TreeNode{10, nullptr, nullptr});
            right = std::unique_ptr<TreeNode>{new TreeNode{20, std::move(left_child), std::move(right_child)}};
        }
        std::cout << "Is same: " << is_same_tree(left, right) << std::endl;
    }
    {
        std::unique_ptr<TreeNode> left;
        {
            std::unique_ptr<TreeNode> left_child(new TreeNode{10, nullptr, nullptr});
            left = std::unique_ptr<TreeNode>{new TreeNode{20, std::move(left_child), nullptr}};
        }
        std::unique_ptr<TreeNode> right;
        {
            std::unique_ptr<TreeNode> right_child(new TreeNode{10, nullptr, nullptr});
            right = std::unique_ptr<TreeNode>{new TreeNode{20, nullptr, std::move(right_child)}};
        }
        std::cout << "Is same: " << is_same_tree(left, right) << std::endl;
    }

    return EXIT_SUCCESS;
}