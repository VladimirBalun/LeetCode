#include "../Helpers.hpp"

// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
// Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
// Hence return [3, 14.5, 11].

// Example 2:
// Input: root = [3,9,20,15,7]
// Output: [3.00000,14.50000,11.00000]

class Solution
{
public:
    std::vector<double> averageOfLevels(TreeNode* root)
    {
        if (!root)
            return std::vector<double>{};

        std::vector<double> levels;
        std::queue<TreeNode*> queue;
        queue.push(root);

        while (!queue.empty()) {
            double level_sum = 0;
            const int size = queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode* node = queue.front();
                queue.pop();

                level_sum += node->val;
                if (node->left)
                    queue.push(node->left);
                if (node->right)
                    queue.push(node->right);
            }

            levels.push_back(level_sum / size);
        }

        return levels;
    }
};