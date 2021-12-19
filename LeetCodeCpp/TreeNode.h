#pragma once
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

#include<vector>;
using namespace std;
TreeNode* BuildTreeNode(vector<int> nodeValues);