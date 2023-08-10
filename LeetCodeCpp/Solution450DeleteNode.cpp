#include "stdafx.h"

class Solution450DeleteNode{
public:
    int _maxValue = INT32_MAX;
    int _minValue = INT32_MIN;

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root->val == key) {
            if (root->left != nullptr) {
                root->left->right = root->right;
                return root->left;
            }
            else if (root->right != nullptr) {
                root->right->left = root->left;
                return root->right;
            }
        }
    }
};
