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

class Solution110IsBalanced
{
private:
	bool _notBalance = false;
	int GetTreeHeight(TreeNode* root, int currentHeight) {
		if (root == nullptr || _notBalance) {
			return currentHeight;
		}
		else {
			++currentHeight;
			int leftTreeHeight = GetTreeHeight(root->left, currentHeight);
			int rightTreeHeight = GetTreeHeight(root->right, currentHeight);

			if (abs(leftTreeHeight - rightTreeHeight) > 1) {
				_notBalance = true;
			}

			return max(leftTreeHeight, rightTreeHeight);
		}
	}

public:
	bool isBalanced(TreeNode* root) {
		if (root == nullptr) {
			return true;
		}

		int leftTreeHeight = GetTreeHeight(root->left, 1);
		int rightTreeHeight = GetTreeHeight(root->right, 1);

		if (_notBalance) {
			return false;
		}
		else {
			return abs(leftTreeHeight - rightTreeHeight) <= 1;
		}
	}
};

int main() {
	Solution110IsBalanced solution;
	vector<int> treeNodeValues1{ 1,2,3,4,5,6,INT32_MAX,8 };
	auto treeNode1 = BuildTreeNode(treeNodeValues1);

	vector<int> treeNodeValues2{ 3,9,20,INT32_MAX,INT32_MAX,15,7 };
	auto treeNode2 = BuildTreeNode(treeNodeValues2);

	vector<int> treeNodeValues3{ 1,2,2,3,3,INT32_MAX,INT32_MAX,4,4 };
	auto treeNode3 = BuildTreeNode(treeNodeValues3);

	cout << solution.isBalanced(treeNode1) << endl;
	cout << solution.isBalanced(treeNode2) << endl;
	cout << solution.isBalanced(treeNode3) << endl;
}