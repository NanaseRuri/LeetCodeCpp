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

class Solution2055PlatesBetweenCandles
{
public:
	vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
		int n = s.length();
		vector<int> preSum(n);

		for (int i = 0, sum = 0; i < n; i++)
		{
			if (s[i] == '*') {
				++sum;
			}
			preSum[i] = sum;
		}

		vector<int> left(n);
		for (int i = 0, l = -1; i < n; i++)
		{
			if (s[i] == '|') {
				l = i;
			}
			left[i] = l;
		}

		vector<int> right(n);
		for (int i = n - 1, r = -1; i >= 0; i--)
		{
			if (s[i] == '|') {
				r = i;
			}
			right[i] = r;
		}

		vector<int> result;
		for (auto& query : queries)
		{
			int x = right[query[0]];
			int y = left[query[1]];

			result.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);
		}

		return result;
	}
};

//int main() {
//	string s1 = "**|**|***|";
//	vector<vector<int>> queries1{ {2,5},{5,9} };
//	string s2 = "***|**|*****|**||**|*";
//	vector<vector<int>> queries2{ {1,17} ,{4,5},{14,17},{5,11},	{15,16} };
//
//	Solution2055PlatesBetweenCandles solution;
//
//	solution.platesBetweenCandles(s1, queries1);
//	solution.platesBetweenCandles(s2, queries2);
//}