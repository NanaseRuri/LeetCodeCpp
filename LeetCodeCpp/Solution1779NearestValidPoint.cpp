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

class Solution1779NearestValidPoint
{
public:
	int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
		int minDistance = INT32_MAX;
		int result = -1;
		int pointsSize = points.size();
		int currentDistance;

		for (int i = 0; i < pointsSize && minDistance != 0; i++)
		{
			if (points[i][0] == x) {
				currentDistance = abs(points[i][1] - y);
				if (currentDistance < minDistance) {
					minDistance = currentDistance;
					result = i;
				}
			}
			else if (points[i][1] == y) {
				currentDistance = abs(points[i][0] - x);
				if (currentDistance < minDistance) {
					minDistance = currentDistance;
					result = i;
				}
			}
		}

		return result;
	}
};
