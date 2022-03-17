#include "../Helpers.hpp"

// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }

// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
// Initially, all next pointers are set to NULL.

// Example 1:
// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

// Example 2:
// Input: root = []
// Output: []

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (!root)
            return root;

        std::queue<Node*> queue;
        queue.push(root);

        while (!queue.empty()) {
            const size_t row_size = queue.size();
            for (size_t i = 0u; i < row_size; ++i) {
                Node* node = queue.front();
                queue.pop();
                
                if (node->left && node->right) {
                    queue.push(node->left);
                    queue.push(node->right);
                }

                Node* next_node = (i == row_size - 1u) ? nullptr : queue.front();
                node->next = next_node;
                node = next_node;
            }
        }

        return root;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
