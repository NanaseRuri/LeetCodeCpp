#include "stdafx.h"

class Solution589PreorderOfNTree {
	vector<int> _result;
public:
	vector<int> preorder1(Node* root) {
		vector<int> result;
		if (root == nullptr) {
			return result;
		}

		stack<Node*> stack{ {root} };
		while (!stack.empty())
		{
			Node* node = stack.top();
			stack.pop();
			result.push_back(node->val);
			for (auto it = node->children.rbegin(); it != node->children.rend(); it++)
			{
				stack.push(*it);
			}
		}

		return result;
	}

	vector<int> preorder(Node* root) {
		_result.clear();

		if (root != nullptr) {
			Dfs(root);
		}

		return _result;
	}

	void Dfs(Node* root) {
		_result.push_back(root->val);

		for (auto& child : root->children)
		{
			Dfs(child);
		}
	}
};
