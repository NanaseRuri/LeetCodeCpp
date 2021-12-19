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

class Solution099RecoverTree
{
public:
	void recoverTree(TreeNode* root) {
		stack<TreeNode*> treeNodeStack;

		long long lastValue = (long long)INT32_MIN - 1;
		TreeNode* dump = root;
		vector<TreeNode*> treeNodeVector;
		while (!treeNodeStack.empty() || root != nullptr)
		{
			while (root != nullptr)
			{
				treeNodeStack.push(root);
				root = root->left;
			}
			root = treeNodeStack.top();
			treeNodeStack.pop();
			treeNodeVector.push_back(root);
			root = root->right;
		}

		TreeNode* preTreeNode = treeNodeVector[0];
		TreeNode* postTreeNode = treeNodeVector[1];
		bool findPreValue = false;
		int treeNodeValuesSize = treeNodeVector.size();

		for (int i = 1; i < treeNodeValuesSize; i++)
		{
			if (treeNodeVector[i]->val < treeNodeVector[i - 1]->val) {
				if (!findPreValue) {
					findPreValue = true;
					preTreeNode = treeNodeVector[i - 1];
					postTreeNode = treeNodeVector[i];
				}
				else {
					postTreeNode = treeNodeVector[i];
					break;
				}
			}
		}

		int temp = preTreeNode->val;
		preTreeNode->val = postTreeNode->val;
		postTreeNode->val = temp;
	}

	void recoverTree2(TreeNode* root) {
		TreeNode* x = nullptr, * y = nullptr, * pred = nullptr, * preValue = nullptr;

		while (root != nullptr)
		{
			if (root->left != nullptr) {
				preValue = root->left;
				while (preValue->right != nullptr && preValue->right != root)
				{
					preValue = preValue->right;
				}

				if (preValue->right == nullptr) {
					preValue->right = root;
					root = root->left;
				}
				else {
					if (pred != nullptr && root->val < pred->val) {
						y = root;
						if (x == nullptr) {
							x = pred;
						}
					}
					pred = root;
					preValue->right = nullptr;
					root = root->right;
				}
			}
			else {
				if (pred != nullptr && root->val < pred->val) {
					y = root;
					if (x == nullptr) {
						x = pred;
					}
				}
				pred = root;
				root = root->right;
			}
		}
		swap(x->val, y->val);
	}
};

//int main() {
//	vector<int> treeNodeValues{ 3,1,4,INT32_MAX,INT32_MAX,2 };
//
//	auto treeNode = BuildTreeNode(treeNodeValues);
//
//	Solution099RecoverTree solution;
//	solution.recoverTree2(treeNode);
//}