#include "stdafx.h"

using namespace std;

class Solution100IsSameTree
{
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        else if (p == nullptr || q == nullptr) {
            return false;
        }

        if (p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else {
            return false;
        }
    }
};
