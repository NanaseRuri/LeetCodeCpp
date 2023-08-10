#include "stdafx.h"

using namespace std;

class Solution1638CountSubstrings
{
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& points) {
		sort(points.begin(), points.end());

		int result = 0;
		for (auto i = 1; i < points.size(); i++)
		{
			result = max(result, points[i][0] - points[i - 1][0]);
		}

		return result;
	}

	int maxWidthOfVerticalArea1(vector<vector<int>>& points) {
		int n = points.size();
		int maxValue = INT32_MIN;
		int minValue = INT32_MAX;

		for (auto& point : points) {
			maxValue = max(maxValue, point[0]);
			minValue = min(minValue, point[0]);
		}

		int bucketSize = max((maxValue - minValue) / (n - 1), 1);
		int bucketCount = (maxValue - minValue) / bucketSize + 1;
		vector<pair<int, int>> buckets(bucketCount, pair<int, int>{INT32_MAX - 1, 0});

		for (auto& point : points) {
			int bucketIndex = (point[0] - minValue) / bucketSize;
			buckets[bucketIndex].first = min(buckets[bucketIndex].first, point[0]);
			buckets[bucketIndex].second = max(buckets[bucketIndex].second, point[0]);
		}

		int result = 0;
		int preValue = INT32_MAX - 1;
		for (auto& [curMin, curMax] : buckets) {
			if (curMin > curMax) {
				continue;
			}
			result = max(result, curMin - preValue);
			preValue = curMax;
		}
		return result;
	}
};

//int main() {
//	vector<vector<int>> points1{ {8,7},{9,9},{7,4},{9,7} };
//	vector<vector<int>> points2{
//		{3,1} ,
//		{9,0},
//		{1,0},
//		{1,4},
//		{5,3},
//		{8,8}
//	};
//
//	Solution1638CountSubstrings solution;
//	solution.maxWidthOfVerticalArea1(points1);
//	solution.maxWidthOfVerticalArea1(points2);
//}
