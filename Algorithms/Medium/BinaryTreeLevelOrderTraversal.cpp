#include "../Helpers.hpp"

// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []

class Solution
{
public:
    std::vector<std::vector<int>> levelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()) {
            const size_t queue_size = queue.size();
            std::vector<int> row(queue_size);
            for (size_t i = 0u; i < queue_size; ++i) {
                TreeNode* node = queue.front();
                row[i] = node->val;
                queue.pop();

                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }
            result.push_back(std::move(row));
        }

        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
