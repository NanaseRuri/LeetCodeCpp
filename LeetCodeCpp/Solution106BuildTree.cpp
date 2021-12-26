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

class Solution106BuildTree
{
private:
	TreeNode* GetTree(vector<int>& inorder, vector<int>& postorder, int inorderLeftIndex, int inorderRightIndex, int postorderLeftIndex, int postorderRightIndex) {
		if (inorderLeftIndex == inorderRightIndex) {
			return new TreeNode(inorder[inorderLeftIndex]);
		}
		if (inorderLeftIndex > inorderRightIndex) {
			return nullptr;
		}

		int headValue = postorder[postorderRightIndex];
		TreeNode* head = new TreeNode(headValue);
		int indexOfHeadValueInInorder = 0;
		while (inorder[indexOfHeadValueInInorder] != headValue)
		{
			indexOfHeadValueInInorder++;
		}

		head->left = GetTree(inorder, postorder, inorderLeftIndex, indexOfHeadValueInInorder - 1, postorderLeftIndex, postorderLeftIndex + indexOfHeadValueInInorder - inorderLeftIndex - 1);
		head->right = GetTree(inorder, postorder, indexOfHeadValueInInorder + 1, inorderRightIndex, postorderLeftIndex + indexOfHeadValueInInorder - inorderLeftIndex, postorderRightIndex - 1);
		return head;
	}

public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int rightIndex = postorder.size() - 1;

		return GetTree(inorder, postorder, 0, rightIndex, 0, rightIndex);
	}
};

//int main() {
//	vector<int> inorder1{ 3,4,5,6,7,8,9 };
//	vector<int> postorder1{ 3,4,5,7,8,9,6 };
//
//	Solution106BuildTree solution;
//	solution.buildTree(inorder1, postorder1);
//}