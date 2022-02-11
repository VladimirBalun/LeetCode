#include "../Helpers.hpp"

class Solution
{
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        std::function<void(TreeNode*)> impl;
        impl = [&impl, &result] (TreeNode* node)
        {
        	if (node->left) {
        		impl(node->left);
        	}

        	result.push_back(node->val);
        	if (node->right) {
        		impl(node->right);
        	}
        };

        if (root) {
        	impl(root);
        }

        return result;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}