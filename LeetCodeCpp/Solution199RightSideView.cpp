#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include <set>


using namespace std;

class Solution199RightSideView
{
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        queue<TreeNode*> treeNodeStack{ {root} };
        while (!treeNodeStack.empty())
        {
            int treeNodeStackSize = treeNodeStack.size();
            for (int i = 0; i < treeNodeStackSize; i++)
            {
                TreeNode* currentTreeNode = treeNodeStack.front();
                treeNodeStack.pop();
                if (i == treeNodeStackSize - 1) {
                    result.push_back(currentTreeNode->val);
                }

                if (currentTreeNode->left != nullptr) {
                    treeNodeStack.push(currentTreeNode->left);
                }
                if (currentTreeNode->right != nullptr) {
                    treeNodeStack.push(currentTreeNode->right);
                }
            }
        }

        return result;
    }
};
