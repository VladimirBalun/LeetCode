#include "../Helpers.hpp"

// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

// Example 1:
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2:
// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,3] and [3,1] are both a height-balanced BSTs.

class Solution
{
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums)
    {
        if (nums.empty()) {
            return nullptr;
        }

        std::function<TreeNode*(size_t, size_t)> impl;
        impl = [&nums, &impl](int left, int right) -> TreeNode*
        {
            if (left > right) {
                return nullptr;
            }

            TreeNode* node = new TreeNode;
            const int middle = left + (right - left) / 2;
            node->val = nums[middle];
            node->left = impl(left, middle - 1);
            node->right = impl(middle + 1, right);
            return node;
        };

        return impl(0, nums.size() - 1);
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
