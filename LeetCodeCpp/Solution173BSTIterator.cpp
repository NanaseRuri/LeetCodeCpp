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
class BSTIterator {
private:
	stack<TreeNode*> _leftStack;
public:
	BSTIterator(TreeNode* root) {
		while (root != nullptr)
		{
			_leftStack.push(root);
			root = root->left;
		}
	}

	int next() {
		auto treeNode = _leftStack.top();
		_leftStack.pop();
		int result = treeNode->val;
		treeNode = treeNode->right;
		while (treeNode != nullptr)
		{
			_leftStack.push(treeNode);
			treeNode = treeNode->left;
		}
		return result;
	}

	bool hasNext() {
		return !_leftStack.empty();
	}
};