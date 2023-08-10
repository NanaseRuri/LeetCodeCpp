#include "stdafx.h"

using namespace std;

class Solution275HIndex
{
public:
	int hIndex(vector<int>& citations) {
		int citationsSize = citations.size();

		int left = 0;
		int right = citations.size() - 1;
		int h = 0;
		int middle;
		int sign = 1;


		while (left <= right) {
			middle = (right + left) / 2;
			if (citations[middle] < citationsSize - middle) {
				left = left + 1;
			}
			else {
				right = middle - 1;
			}
		}

		return citationsSize - left;
	}
};

//int main() {
//	Solution275HIndex solution;
//	vector<int> nums1{ 0,1,3,5,6 };
//	vector<int> nums2{ 1,2,100 };
//	vector<int> nums3{ 0 };
//	solution.hIndex(nums1);
//	solution.hIndex(nums2);
//	solution.hIndex(nums3);
//}
