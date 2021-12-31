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

using namespace std;

class Solution124MaxPathSum
{
private:
	int _currentMax = INT32_MIN;
	unordered_map<TreeNode*, int> _treeNodePathValue;
	void GetMaxSum(TreeNode* root) {
		if (root == nullptr) {
			return;
		}

		int currentSum = root->val;
		int leftMaxSum = GetSinglePathMaxSum(root->left);
		int rightMaxSum = GetSinglePathMaxSum(root->right);
		if (leftMaxSum > 0) {
			currentSum += leftMaxSum;
		}
		if (rightMaxSum > 0) {
			currentSum += rightMaxSum;
		}

		_currentMax = max(_currentMax, currentSum);

		GetMaxSum(root->left);
		GetMaxSum(root->right);
	}

	int GetSinglePathMaxSum(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		if (_treeNodePathValue.find(root) != _treeNodePathValue.end()) {
			return _treeNodePathValue[root];
		}
		int currentSum = root->val;
		int leftPathValue = GetSinglePathMaxSum(root->left);
		int rightPathValue = GetSinglePathMaxSum(root->right);
		int maxPathValue = max(leftPathValue, rightPathValue);
		if (maxPathValue > 0) {
			currentSum += maxPathValue;
		}
		_treeNodePathValue.insert({ root, currentSum });
		return currentSum;
	}

public:
	int maxPathSum1(TreeNode* root) {
		_currentMax = INT32_MIN;
		_treeNodePathValue.clear();
		GetMaxSum(root);

		return _currentMax;
	}

	int maxPathSum(TreeNode* root) {
		_currentMax = INT32_MIN;

		MaxGain(root);
		return _currentMax;
	}

	int MaxGain(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}

		int rootValue = root->val;
		int leftGain = max(MaxGain(root->left), 0);
		int rightGain = max(MaxGain(root->right), 0);

		int currentMax = rootValue + leftGain + rightGain;

		_currentMax = max(_currentMax, currentMax);

		return rootValue + max(leftGain, rightGain);
	}
};

//int main() {
//	vector<int> treeNodeValues1{ 1,2,3 };
//	vector<int> treeNodeValues2{ -10,9,20,INT32_MAX,INT32_MAX,15,7 };
//	vector<int> treeNodeValues3{ 1,INT32_MAX,2,INT32_MAX,3,INT32_MAX,4,INT32_MAX,5 };
//
//	TreeNode* treeNode1 = BuildTreeNode(treeNodeValues1);
//	TreeNode* treeNode2 = BuildTreeNode(treeNodeValues2);
//	TreeNode* treeNode3 = BuildTreeNode(treeNodeValues3);
//
//	Solution124MaxPathSum solution;
//	solution.maxPathSum1(treeNode1);
//	solution.maxPathSum1(treeNode2);
//	solution.maxPathSum1(treeNode3);
//}