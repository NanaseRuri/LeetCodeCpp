#include "stdafx.h"

using namespace std;

class Solution257BinaryTreePaths
{
private:
	vector<string> _result;

	void Dfs(TreeNode* root, string currentString) {
		if (root == nullptr) {
			return;
		}
		currentString += to_string(root->val);
		if (root->left == nullptr && root->right == nullptr) {
			_result.push_back(currentString);
		}
		else {
			currentString += "->";
			if (root->left != nullptr) {
				Dfs(root->left, currentString);
			}
			if(root->right != nullptr) {
				Dfs(root->right, currentString);
			}
		}
	}

public:
	vector<string> binaryTreePaths(TreeNode* root) {
		_result.clear();
		Dfs(root, "");
		return _result;
	}
};
