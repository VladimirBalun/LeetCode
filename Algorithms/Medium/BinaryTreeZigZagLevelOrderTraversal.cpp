#include "../Helpers.hpp"

// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []

class Solution
{
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        std::vector<std::vector<int>> result;
        if (!root) {
            return result;
        }

        bool zigzag = false;
        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            const size_t size = queue.size();
            std::vector<int> tree_row(size);
            for (size_t i = 0u; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                if (zigzag) {
                    tree_row[size - i - 1] = node->val;
                } else {
                    tree_row[i] = node->val;
                }

                if (node->left) {
                    queue.push(node->left);
                }
                if (node->right) {
                    queue.push(node->right);
                }
            }

            zigzag = !zigzag;
            result.push_back(std::move(tree_row));
        }
        
        return result;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
