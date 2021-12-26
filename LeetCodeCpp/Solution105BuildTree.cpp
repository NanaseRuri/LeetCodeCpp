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

class Solution105BuildTree
{
	TreeNode* GetTree(vector<int>& preorder, vector<int>& inorder, int preorderLeftIndex, int inorderLeftIndex, int inorderRightIndex) {
		if (inorderLeftIndex == inorderRightIndex) {
			return new TreeNode(preorder[preorderLeftIndex]);
		}
		if (inorderLeftIndex > inorderRightIndex) {
			return nullptr;
		}

		int headValue = preorder[preorderLeftIndex];
		TreeNode* head = new TreeNode(headValue);
		int middleIndex = inorderLeftIndex;

		while (inorder[middleIndex] != headValue)
		{
			middleIndex++;
		}

		head->left = GetTree(preorder, inorder, preorderLeftIndex + 1, inorderLeftIndex, middleIndex - 1);
		head->right = GetTree(preorder, inorder, preorderLeftIndex + 1 + middleIndex - inorderLeftIndex, middleIndex + 1, inorderRightIndex);

		return head;
	}

public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int preOrderSize = preorder.size();
		int leftIndex = 0;
		int rightIndex = preOrderSize - 1;
		int middleIndexOfIorder;

		return GetTree(preorder, inorder, 0, 0, rightIndex);
	}
};

//int main() {
//	vector<int> preorder1{ 3,9,20,15,7 };
//	vector<int> inorder1{ 9,3,15,20,7 };
//
//	vector<int> preorder2{ 6,4,3,5,8,7,9 };
//	vector<int> inorder2{ 3,4,5,6,7,8,9 };
//
//	Solution105BuildTree solution;
//
//	solution.buildTree(preorder1, inorder1);
//	solution.buildTree(preorder2, inorder2);
//}