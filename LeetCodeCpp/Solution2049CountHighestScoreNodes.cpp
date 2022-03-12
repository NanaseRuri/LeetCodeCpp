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
#include "Node.h"
#include <set>

using namespace std;

class Solution2049CountHighestScoreNodes
{
private:
	long long _maxScore = 0;
	int _result = 0;
	int _nodeSize;
	vector<vector<int>> _children;

public:
	int countHighestScoreNodes(vector<int>& parents) {
		_nodeSize = parents.size();
		_children = vector<vector<int>>(_nodeSize);
		for (int i = 0; i < _nodeSize; i++)
		{
			int p = parents[i];
			if (p != -1) {
				_children[p].push_back(i);
			}
		}

		Dfs(0);
		return _result;
	}

	int Dfs(int node) {
		long long score = 1;
		int size = _nodeSize - 1;

		for (int& c : _children[node])
		{
			int t = Dfs(c);
			score *= t;
			size -= t;
		}

		if (node != 0) {
			score *= size;
		}
		if (score == _maxScore) {
			_result++;
		}
		else if (score > _maxScore) {
			_maxScore = score;
			_result = 1;
		}

		return _nodeSize - size;
	}
};