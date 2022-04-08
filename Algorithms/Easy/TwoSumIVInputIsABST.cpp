#include "../Helpers.hpp"

// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

// Example 1:
// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true

// Example 2:
// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false

class Solution
{
public:
    bool findTarget(TreeNode* root, int k)
    {
        std::unordered_set<int> lookup;
        std::stack<TreeNode*> stack;
        stack.push(root);

        while (!stack.empty()) {
            TreeNode* node = stack.top();
            stack.pop();
            
            const int diff = k - node->val;
            if (lookup.count(diff) == 0)
                lookup.insert(node->val);
            else
                return true;
            
            if (node->left)
                stack.push(node->left);
            if (node->right)
                stack.push(node->right);
        }
        
        return false;
    }
};

int main(int argc, char** argv)
{
	return EXIT_SUCCESS;
}