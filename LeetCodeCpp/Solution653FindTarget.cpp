#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution653FindTarget {
public:
	bool findTarget(TreeNode* root, int k) {
		unordered_set<int> valueMap;
		stack<TreeNode*> treeNodeStack{ {root} };
		while (!treeNodeStack.empty())
		{
			TreeNode* currentNode = treeNodeStack.top();
			treeNodeStack.pop();
			if (valueMap.find(k - currentNode->val) != valueMap.end()) {
				return true;
			}

			valueMap.insert(currentNode->val);
			if (currentNode->left != nullptr)
			{
				treeNodeStack.push(currentNode->left);
			}
			if (currentNode->right != nullptr) {
				treeNodeStack.push(currentNode->right);
			}
		}

		return false;
	}
};