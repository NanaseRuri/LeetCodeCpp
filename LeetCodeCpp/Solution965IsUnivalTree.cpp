#include "stdafx.h"

class Solution965IsUnivalTree
{
public:
    bool isUnivalTree(TreeNode* root) {
        return IsUnivalTree(root, root->val);
    }

    bool IsUnivalTree(TreeNode* root, int value) {
        return root == nullptr || (root->val == value && IsUnivalTree(root->left, value) && IsUnivalTree(root->right, value));
    }
};