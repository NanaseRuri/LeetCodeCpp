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

class Solution050MyPow {
public:
	double myPow(double x, int n) {
		if (n == 0) {
			return 1;
		}

		int64_t newN = n > 0 ? (int64_t)n : -(int64_t)n;
		int64_t currentPow = 1;
		double currentValue = x;

		while (currentPow < newN)
		{
			int64_t temp = 1;
			double tempX = x;
			double preTempX;
			while (temp < newN - currentPow)
			{
				preTempX = tempX;
				temp <<= 1;
				tempX *= tempX;
			}

			// ÎÞÇîÐ¡
			if (tempX == 0 || tempX == INFINITY) {
				return 0;
			}

			if (temp > newN - currentPow) {
				temp >>= 1;
				tempX /= preTempX;
			}
			currentPow += temp;
			currentValue *= tempX;
		}

		return n > 0 ? currentValue : 1.0 / currentValue;
	}

	double myPow1(double x, int n) {
		double result = 1;
		double currentPow = x;
		long long longN = n > 0 ? (long long)n : -(long long)n;
		while (longN > 0)
		{
			if (longN % 2 == 1) {
				result *= currentPow;
			}
			currentPow *= currentPow;
			longN >>= 1;
		}
		return n > 0 ? result : 1.0 / result;
	}
};

//int main() {
//	Solution050MyPow solution;
//	double x = 2;
//	int n = 10;
//
//	double x1 = 2;
//	int n1 = -2;
//
//	double x2 = 0.00001;
//	int n2 = INT32_MAX;
//
//	double x3 = 2;
//	int n3 = INT32_MIN;
//
//	cout << solution.myPow(x, n) << endl;
//	cout << solution.myPow(x1, n1) << endl;
//	cout << solution.myPow(x2, n2) << endl;
//	cout << solution.myPow(x3, n3) << endl;
//
//	cout << solution.myPow1(x, n) << endl;
//	cout << solution.myPow1(x1, n1) << endl;
//	cout << solution.myPow1(x2, n2) << endl;
//	cout << solution.myPow1(x3, n3) << endl;
//}