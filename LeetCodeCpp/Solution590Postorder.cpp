#include "stdafx.h"

class Solution589PreorderOfNTree {
public:
	vector<int> postorder(Node* root) {
		vector<int> result;
		if (root == nullptr) {
			return result;
		}

		unordered_map<Node*, int> cnt;
		stack<Node*> st;
		Node* node = root;
		while (!st.empty() || node != nullptr) {
			while (node != nullptr)
			{
				st.push(node);
				if (node->children.size() > 0) {
					cnt[node] = 0;
					node = node->children[0];
				}
				else {
					node = nullptr;
				}
			}

			node = st.top();
			int index = cnt.find(node) != cnt.end() ? (cnt[node] + 1) : 0;
			if (index < node->children.size()) {
				cnt[node] = index;
				node = node->children[index];
			}
			else {
				result.push_back(node->val);
				st.pop();
				cnt.erase(node);
				node = nullptr;
			}
		}

		return result;
	}

	vector<int> postorder1(Node* root) {
		vector<int> result;
		if (root == nullptr) {
			return result;
		}

		stack<Node*> st{ {root} };

		while (!st.empty()) {
			Node* node = st.top();
			st.pop();
			if (node != nullptr) {
				st.push(node);
				st.push(nullptr);

				for (int i = node->children.size() - 1; i >= 0; i--) {
					st.push(node->children[i]);
				}
			}
			else {
				result.push_back(st.top()->val);
				st.pop();
			}
		}

		return result;
	}
};
