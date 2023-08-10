#include "stdafx.h"

using namespace std;

class Solution235LowestCommonAncestor
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > q->val) {
            swap(p, q);
        }

        while (root != nullptr) {
            if (p->val <= root->val && q->val >= root->val) {
                return root;
            }
            else if (p->val < root->val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }

        return root;
    }
};
