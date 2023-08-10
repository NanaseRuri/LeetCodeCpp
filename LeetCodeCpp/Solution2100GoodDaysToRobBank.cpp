#include "stdafx.h"

using namespace std;

class Solution2100GoodDaysToRobBank
{
public:
	vector<int> goodDaysToRobBank(vector<int>& security, int time) {
		int n = security.size();
		vector<int> left(n);
		vector<int> right(n);
		for (int i = 1; i < n; i++)
		{
			if (security[i] <= security[i - 1])
			{
				left[i] = left[i - 1] + 1;
			}
			if (security[n - i - 1] <= security[n - i]) {
				right[n - i - 1] = right[n - i] + 1;
			}
		}

		vector<int> result;
		for (int i = 0; i < n; i++) {
			if (left[i] >= time && right[i] >= time) {
				result.push_back(i);
			}
		}

		return result;
	}

	vector<int> goodDaysToRobBank1(vector<int>& security, int time) {
		vector<int>result;
		int securitySize = security.size();
		if (time == 0) {
			for (int i = 0; i < securitySize; i++)
			{
				result.push_back(i);
			}
		}
		else {
			int iterLength = securitySize - time;
			int left = 0;
			int right = 0;
			for (int i = 1; i < iterLength; i++) {
				if (security[i - 1] >= security[i]) {
					++left;
				}
				else {
					left = 0;
				}
				if (security[i + time] >= security[i + time - 1]) {
					++right;
				}
				else {
					right = 0;
				}

				if (left >= time && right >= time) {
					result.push_back(i);
				}
			}
		}

		return result;
	}
};

//int main() {
//	Solution2016MaximumDifference solution;
//	vector<int> nums1{ 5,3,3,3,5,6,2 };
//	vector<int> nums2{ 1,1,1,1,1 };
//	vector<int> nums3{ 1,2,3,4,5,6 };
//	vector<int> nums4{ 1, 2, 5, 4, 1, 0, 2, 4, 5, 3, 1, 2, 4, 3, 2, 4, 8 };
//	solution.goodDaysToRobBank(nums1, 2);
//	solution.goodDaysToRobBank(nums2, 0);
//	solution.goodDaysToRobBank(nums3, 2);
//	solution.goodDaysToRobBank(nums4, 2);
//	solution.goodDaysToRobBank1(nums1, 2);
//	solution.goodDaysToRobBank1(nums2, 0);
//	solution.goodDaysToRobBank1(nums3, 2);
//	solution.goodDaysToRobBank1(nums4, 2);
//}
