#include "stdafx.h"

using namespace std;

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {};
TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

TreeNode* BuildTreeNode(vector<int> nodeValues) {
	queue<TreeNode*> nodes;
	TreeNode* firstNode = new TreeNode(nodeValues[0]);
	nodes.push(firstNode);

	int nodesSize = nodeValues.size();
	TreeNode* currentNode = nodes.front();
	nodes.pop();

	for (int i = 1; i < nodesSize; i++)
	{
		if (i % 2 == 1) {
			if (nodeValues[i] != INT32_MAX) {
				TreeNode* leftChild = new TreeNode(nodeValues[i]);
				currentNode->left = leftChild;
				nodes.push(leftChild);
			}
		}
		else {
			if (nodeValues[i] != INT32_MAX) {
				TreeNode* rightChild = new TreeNode(nodeValues[i]);
				currentNode->right = rightChild;
				nodes.push(rightChild);
			}
			currentNode = nodes.front();
			nodes.pop();
		}
	}

	return firstNode;
}
