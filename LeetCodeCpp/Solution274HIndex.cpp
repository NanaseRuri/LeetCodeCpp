#include "stdafx.h"

using namespace std;

class Solution274HIndex
{
public:
	int hIndex(vector<int>& citations) {
		sort(citations.begin(), citations.end());

		int h = 0;
		int i = citations.size() - 1;
		while (i >= 0 && citations[i] > h)
		{
			h++;
			i--;
		}
		return h;
	}
	int hIndex1(vector<int>& citations) {
		int n = citations.size();
		int total = 0;
		vector<int> counter(n + 1);
		for (int i = 0; i < n; i++)
		{
			if (citations[i] >= n) {
				++counter[n];
			}
			else {
				++counter[citations[i]];
			}
		}

		for (int i = n; i >= 0; i--)
		{
			total += counter[i];
			if (total >= i) {
				return i;
			}
		}
		return 0;
	}
};

//int main() {
//	Solution274HIndex solution;
//	vector<int> nums1{ 11,15 };
//	cout << solution.hIndex(nums1) << endl;
//}
