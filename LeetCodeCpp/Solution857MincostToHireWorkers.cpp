#include "stdafx.h"

class Solution857MincostToHireWorkers
{
public:
	double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
		int n = quality.size();
		vector<int> workerIndexes(n);
		iota(workerIndexes.begin(), workerIndexes.end(), 0);
		sort(workerIndexes.begin(), workerIndexes.end(), [&](int& a, int& b) {
			return wage[a] * quality[b] < wage[b] * quality[a];
			});

		priority_queue<int, vector<int>, less<int>> qualityQueue;
		double result = 1e9;
		int totalQuality = 0;
		for (int i = 0; i < k - 1; i++)
		{
			totalQuality += quality[workerIndexes[i]];
			qualityQueue.push(quality[workerIndexes[i]]);
		}

		for (int i = k - 1; i < n; i++) {
			int index = workerIndexes[i];
			totalQuality += quality[index];
			qualityQueue.push(quality[index]);
			result = min(result, (double)totalQuality * wage[index] / quality[index]);
			totalQuality -= qualityQueue.top();
			qualityQueue.pop();
		}

		return result;
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