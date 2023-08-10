#include "stdafx.h"

using namespace std;

class Solution1588SumOddLengthSubarrays
{
public:
	int sumOddLengthSubarrays(vector<int>& arr) {
		int n = arr.size();
		vector<int> prefixSums(n + 1);
		for (int i = 0; i < n; i++)
		{
			prefixSums[i + 1] = prefixSums[i] + arr[i];
		}
		int sum = 0;
		for (int start = 0; start < n; start++)
		{
			for (int length = 1; length + start <= n; length += 2)
			{
				int end = start + length;
				sum += prefixSums[end] - prefixSums[start];
			}
		}

		return sum;
	}

	int sumOddLengthSubarrays1(vector<int>& arr) {
		int sum = 0;
		int n = arr.size();

		for (int i = 0; i < n; i++) {
			int leftCount = i;
			int rightCount = n - i - 1;
			int leftOdd = (leftCount + 1) / 2;
			int rightOdd = (rightCount + 1) / 2;
			int leftEven = leftCount / 2 + 1;
			int rightEven = rightCount / 2 + 1;
			sum += arr[i] * (leftOdd * rightOdd + leftEven * rightEven);
		}

		return sum;
	}
};
