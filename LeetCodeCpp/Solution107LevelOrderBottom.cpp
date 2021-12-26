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

using namespace std;

class Solution107LevelOrderBottom
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }

        stack<vector<int>> resultStack;
        vector<int> currentResult;

        queue<TreeNode*> parentNodes;
        queue<TreeNode*> childrenNodes;

        parentNodes.push(root);

        TreeNode* parentNode;
        while (!parentNodes.empty() || !childrenNodes.empty())
        {
            parentNode = parentNodes.front();
            parentNodes.pop();

            currentResult.push_back(parentNode->val);
            if (parentNode->left != nullptr) {
                childrenNodes.push(parentNode->left);
            }
            if (parentNode->right != nullptr) {
                childrenNodes.push(parentNode->right);
            }

            if (parentNodes.empty()) {
                resultStack.push(vector<int>(currentResult));
                currentResult.clear();
                swap(parentNodes, childrenNodes);
            }
        }

        while (!resultStack.empty())
        {
            result.push_back(resultStack.top());
            resultStack.pop();
        }

        return result;
    }
};