#include "stdafx.h"

using namespace std;

class Solution057Insert {
private:
	int GetInsertPos(vector<vector<int>>& intervals, int num) {
		int left = 0;
		if (num <= intervals[left][0]) {
			return 0;
		}

		int right = intervals.size() - 1;
		if (num >= intervals[right][0]) {
			return right + 1;
		}

		int middle;
		while (left <= right) {
			middle = (left + right) / 2;
			if (intervals[middle][0] > num) {
				right = middle - 1;
			}
			else {
				if (intervals[middle + 1][0] < num) {
					left = middle + 1;
				}
				else {
					return middle + 1;
				}
			}
		}
	}

public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
		vector<vector<int>> result;
		int intervalsSize = intervals.size();
		if (intervalsSize == 0) {
			result.push_back(newInterval);
			return result;
		}
		else {
			int insertPosition = GetInsertPos(intervals, newInterval[0]);
			int i = 0;
			for (; i < insertPosition; i++)
			{
				result.push_back(intervals[i]);
			}

			// �Ƿ񵥴����������֮ǰ�ϲ�
			int resultLastIndex = insertPosition - 1;
			if (i > 0 && newInterval[0] <= result[i - 1][1]) {
				result[i - 1][1] = max(result[i - 1][1], newInterval[1]);
			}
			else {
				result.push_back(newInterval);
				++resultLastIndex;
			}

			for (; i < intervalsSize; i++)
			{
				if (intervals[i][0] <= result[resultLastIndex][1]) {
					result[resultLastIndex][1] = max(result[resultLastIndex][1], intervals[i][1]);
				}
				else {
					break;
				}
			}

			for (; i < intervalsSize; i++)
			{
				result.push_back(intervals[i]);
			}
		}
		return result;
	}
};

//int main() {
//	vector<vector<int>> intervals{ {1,3},{6,9} };
//	vector<int> newInterval{ 2,5 };
//
//	vector<vector<int>> intervals1{ {1,2} ,{3,5},{6,7},{8,10},{12,16} };
//	vector<int> newInterval11{ 4,8 };
//	vector<int> newInterval12{ -1,3 };
//	vector<int> newInterval13{ 16,20 };
//
//	vector<vector<int>> intervals2{};
//	vector<int> newInterval2{ 5,7 };
//
//	vector<vector<int>> intervals3{ {1,5} };
//	vector<int> newInterval3{ 2,3 };
//
//	vector<vector<int>> intervals4{ {1,5} };
//	vector<int> newInterval4{ 1,7 };
//
//	vector<vector<int>> intervals5{ {1,5} };
//	vector<int> newInterval5{ 6,7 };
//
//	vector<vector<int>> intervals6{ {1,5} };
//	vector<int> newInterval6{ 0,1 };
//
//	vector<vector<int>> intervals7{ {1,5} };
//	vector<int> newInterval7{ -1,0 };
//
//	Solution057Insert solution;
//	solution.insert(intervals, newInterval);
//	solution.insert(intervals1, newInterval11);
//	solution.insert(intervals1, newInterval12);
//	solution.insert(intervals1, newInterval13);
//
//	solution.insert(intervals2, newInterval2);
//	solution.insert(intervals3, newInterval3);
//	solution.insert(intervals4, newInterval4);
//	solution.insert(intervals5, newInterval5);
//	solution.insert(intervals6, newInterval6);
//	solution.insert(intervals7, newInterval7);
//}
