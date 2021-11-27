#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution056Merge {
private:
	static bool Compare(vector<int>& left, vector<int>& right) {
		return left[0] < right[0];
	}

public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		sort(intervals.begin(), intervals.end(), Compare);

		int intervalsSize = intervals.size();
		vector<vector<int>> result{ intervals[0] };
		int resultLastIndex = 0;
		for (int i = 1; i < intervalsSize; i++)
		{
			if (intervals[i][0] <= result[resultLastIndex][1]) {
				result[resultLastIndex][1] = max(result[resultLastIndex][1], intervals[i][1]);
			}
			else {
				result.push_back(intervals[i]);
				resultLastIndex++;
			}
		}
		return result;
	}
};

//int main() {
//	vector<vector<int>> nums{
//		{2,3},
//		{2,2},
//		{3,3},
//		{1,3},
//		{5,7},
//		{2,2},
//		{4,6} };
//	Solution056Merge solution;
//	solution.merge(nums);
//}