#include "stdafx.h"

class Solution429LevelOrder {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (!root) {
            return result;
        }

        queue<Node*> treeNodeQueue;
        treeNodeQueue.push(root);

        while (!treeNodeQueue.empty()) {
            int cnt = treeNodeQueue.size();
            vector<int> level;
            for (int i = 0; i < cnt; ++i) {
                Node* cur = treeNodeQueue.front();
                treeNodeQueue.pop();
                level.push_back(cur->val);
                for (Node* child : cur->children) {
                    treeNodeQueue.push(child);
                }
            }
            result.push_back(move(level));
        }

        return result;
    }
};
