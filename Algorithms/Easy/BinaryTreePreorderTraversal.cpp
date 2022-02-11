#include "../Helpers.hpp"

class Solution
{
public:
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        std::vector<int> result;
        std::function<void(TreeNode*)> impl;
        impl = [&impl, &result] (TreeNode* node)
        {
        	result.push_back(node->val);
        	if (node->left) {
        		impl(node->left);
        	}
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