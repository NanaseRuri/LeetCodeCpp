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

using namespace std;

class Solution120MinimumTotal
{
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int triangleSize = triangle.size();

		vector<int> currentLayer(triangleSize);
		currentLayer[0] = triangle[0][0];
		vector<int> nextLayer(triangleSize);

		for (int i = 1; i < triangleSize; i++)
		{
			nextLayer[0] = triangle[i][0] + currentLayer[0];
			nextLayer[i] = triangle[i][i] + currentLayer[i - 1];
			for (int j = 1; j < i; j++)
			{
				nextLayer[j] = triangle[i][j] + min(currentLayer[j], currentLayer[j - 1]);
			}

			swap(currentLayer, nextLayer);
		}

		int minValue = INT32_MAX;
		for (int i = 0; i < triangleSize; i++)
		{
			minValue = min(minValue, currentLayer[i]);
		}

		return minValue;
	}
};