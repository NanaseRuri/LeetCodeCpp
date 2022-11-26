#include "stdafx.h"

class Solution1619TrimMean
{
public:
	double trimMean(vector<int>& arr) {
		int n = arr.size();
		int count = n / 20;
		priority_queue<int, vector<int>, less<int>> maxHeap{ arr.begin(),arr.begin() + count };
		priority_queue<int, vector<int>, greater<int>> minHeap{ arr.begin(),arr.begin() + count };

		double sum = accumulate(arr.begin(), arr.begin() + count, 0);

		for (int i = count; i < n; i++)
		{
			int currentValue = arr[i];
			sum += currentValue;
			maxHeap.push(currentValue);
			minHeap.push(currentValue);
			maxHeap.pop();
			minHeap.pop();
		}

		for (int i = 0; i < count; i++) {
			sum -= maxHeap.top();
			sum -= minHeap.top();

			maxHeap.pop();
			minHeap.pop();
		}

		return sum / (n - count * 2);
	}
};

//int main() {
//	Solution857MincostToHireWorkers solution;
//	vector<int> quality1{ 10,20,5 };
//	vector<int> wage1{ 70,50,30 };
//	int k1 = 2;
//
//	vector<int> quality2{ 3,1,10,10,1 };
//	vector<int> wage2{ 4,8,2,2,7 };
//	int k2 = 3;
//
//	solution.mincostToHireWorkers(quality1, wage1, k1);
//	solution.mincostToHireWorkers(quality2, wage2, k2);
//}