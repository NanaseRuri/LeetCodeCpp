#include "stdafx.h"

using namespace std;

class Solution145PostorderTraversal
{
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> result;
		stack<TreeNode*> nodeStack;

		TreeNode* preTreeNode = nullptr;
		while (root != nullptr || !nodeStack.empty())
		{
			while (root != nullptr)
			{
				nodeStack.push(root);
				root = root->left;
			}
			root = nodeStack.top();
			nodeStack.pop();
			// �ҽڵ�û�л򱻷��ʹ�
			if (root->right == nullptr || root->right == preTreeNode) {
				result.push_back(root->val);
				preTreeNode = root;
				root = nullptr;
			}
			else {
				nodeStack.push(root);
				root = root->right;
			}
		}
		return result;
	}
};

//int main() {
//	vector<int> treeNodeValue{ 1,2,3,4,5,6,7 };
//
//	auto treeNode = BuildTreeNode(treeNodeValue);
//	Solution145PostorderTraversal solution;
//	solution.postorderTraversal(treeNode);
//}
