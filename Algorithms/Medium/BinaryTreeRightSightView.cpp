#include "../Helpers.hpp"

// Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

// Example 1:
// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]

// Example 2:
// Input: root = [1,null,3]
// Output: [1,3]

// Example 3:
// Input: root = []
// Output: []

class Solution
{
public:
    std::vector<int> rightSideView(TreeNode* root)
    {
        if (!root) {
            return std::vector<int>{};
        }

        std::vector<int> result;
        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            const size_t size = queue.size();
            for (size_t i = 0u; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                if (i == size - 1u) {
                   result.push_back(node->val); 
                }
                
                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }                
            }
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
