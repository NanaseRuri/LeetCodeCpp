#include "stdafx.h"

using namespace std;

class Solution094InorderTraversal
{
public:
	vector<int> inorderTraversal(TreeNode* root) {
		if (root == nullptr) {
			return vector<int>();
		}

		vector<int> result;
		stack<TreeNode*> treeNodeStack;
		TreeNode* currentNode = root;

		treeNodeStack.push(root);

		while (currentNode->left != nullptr)
		{
			treeNodeStack.push(currentNode->left);
			currentNode = currentNode->left;
		}

		while (!treeNodeStack.empty())
		{
			currentNode = treeNodeStack.top();
			treeNodeStack.pop();
			result.push_back(currentNode->val);
			if (currentNode->right != nullptr) {
				TreeNode* tempNode = currentNode->right;
				treeNodeStack.push(tempNode);

				while (tempNode->left != nullptr)
				{
					treeNodeStack.push(tempNode->left);
					tempNode = tempNode->left;
				}
			}
		}

		return result;
	}
};

//int main() {
//	vector<int> treeNodeValue = { 1,INT32_MAX,2,3 };
//	auto treeNode = BuildTreeNode(treeNodeValue);
//	Solution094InorderTraversal solution;
//	solution.inorderTraversal(treeNode);
//}
