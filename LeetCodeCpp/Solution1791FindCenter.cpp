#include "stdafx.h"

using namespace std;

class Solution1791FindCenter
{
public:
	int findCenter(vector<vector<int>>& edges) {
		unordered_map<int, int> numsCount;
		for (int i = 0; i < 2; i++)
		{
			++numsCount[edges[i][0]];
			++numsCount[edges[i][1]];
		}

		int center = 0;
		int count = 0;
		for (auto& pair : numsCount)
		{
			if (pair.second > count) {
				count = pair.second;
				center = pair.first;
			}
		}
		return center;
	}

	int findCenter1(vector<vector<int>>& edges) {
		return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1] ? edges[0][0] : edges[0][1];
	}
};
