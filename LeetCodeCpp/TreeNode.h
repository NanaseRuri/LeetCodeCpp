#pragma once
#include<vector>

using namespace std;
class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode();
	TreeNode(int x);
	TreeNode(int x, TreeNode* left, TreeNode* right);
};

TreeNode* BuildTreeNode(vector<int> nodeValues);