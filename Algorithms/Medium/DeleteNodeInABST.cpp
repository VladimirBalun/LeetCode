#include "../Helpers.hpp"

// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

// Basically, the deletion can be divided into two stages:
// Search for a node to remove.
// If the node is found, delete the node.

// Example 1:
// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
// Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
// One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
// Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

// Example 2:
// Input: root = [5,3,6,2,4,null,7], key = 0
// Output: [5,3,6,2,4,null,7]
// Explanation: The tree does not contain a node with value = 0.

// Example 3:
// Input: root = [], key = 0
// Output: []

class Solution
{
public:
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        TreeNode* current = root;
        TreeNode* parent = nullptr;
        
        while (current) {
            if (key < current->val) {
                parent = current;
                current = current->left;
            } else if (key > current->val) {
                parent = current;
                current = current->right;
            } else {
                break;
            }
        }

        if (!current)
            return root;

        if (!current->right) {
            if (parent) {
                if (current == parent->left)
                    parent->left = current->left;
                else
                    parent->right = current->left;
            } else {
                return current->left;
            }
        } else {
            TreeNode* parent = current;
            TreeNode* min = current->right;
            while (min->left) {
                parent = min;
                min = min->left;
            }

            current->val = min->val;
            if (min == parent->left)
                parent->left = min->right;
            else
                parent->right = min->right;
        }
        
        return root;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}