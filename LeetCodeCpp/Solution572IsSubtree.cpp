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

class Solution572IsSubtree {
public:
	bool isSubtree(TreeNode* root, TreeNode* subRoot) {
		if (root == nullptr && subRoot == nullptr) {
			return true;
		}
		else if (root == nullptr || subRoot == nullptr) {
			return false;
		}

		stack<TreeNode*> rootStack{ {root} };

		while (!rootStack.empty()) {
			TreeNode* currentRoot = rootStack.top();
			rootStack.pop();

			if (Dfs(currentRoot, subRoot)) {
				return true;
			}
			
			if (currentRoot->left != nullptr) {
				rootStack.push(currentRoot->left);
			}
			if (currentRoot->right != nullptr) {
				rootStack.push(currentRoot->right);
			}
		}
		return false;
	}

	bool Dfs(TreeNode* root, TreeNode* subRoot) {
		if (root == nullptr && subRoot == nullptr) {
			return true;
		}
		else if (root == nullptr || subRoot == nullptr) {
			return false;
		}
		return (root->val == subRoot->val && Dfs(root->left, subRoot->left) && Dfs(root->right, subRoot->right));
	}
};

//int main() {
//	auto treeNode1 = BuildTreeNode({ 3,4,5,1,INT32_MAX,2 });
//	auto treeNode2 = BuildTreeNode({ 3,1,2 });
//
//	Solution572IsSubtree solution;
//	solution.isSubtree(treeNode1, treeNode2);
//}