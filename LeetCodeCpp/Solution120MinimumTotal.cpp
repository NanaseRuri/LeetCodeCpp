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

	int minimumTotal1(vector<vector<int>>& triangle) {
		vector<int> result{ triangle[0][0] };

		int triangleSize = triangle.size();
		for (int i = 1; i < triangleSize; i++) {
			vector<int> newResult(i + 1);
			newResult[0] = result[0] + triangle[i][0];

			for (int j = 1; j < i; j++) {
				newResult[j] = min(result[j], result[j - 1]) + triangle[i][j];
			}
			newResult[i] = result[i - 1] + triangle[i][i];

			swap(newResult, result);
		}

		return *min_element(result.begin(), result.end());
	}
};

//int main() {
//	Solution120MinimumTotal solution;
//	vector<vector<int>>triangle{ {2},{3,4},{6,5,7},{4,1,8,3} };
//	solution.minimumTotal1(triangle);
//}