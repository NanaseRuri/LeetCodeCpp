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

class Solution069MySqrt
{
public:
	int mySqrt(int x) {
		if (x == 0) {
			return 0;
		}

		double c = x, x0 = x;
		while (true)
		{
			double xi = 0.5 * (x0 + c / x0);
			if (abs(x0 - xi) < 1e-7) {
				break;
			}
			x0 = xi;
		}
		return x0;
	}

	int mySqrt1(int x) {
		if (x == 0) {
			return 0;
		}

		long long x0 = exp(0.5 * log(x));
		return (x0 + 1) * (x0 + 1) <= x ? x0 + 1 : x0;
	}
};

//int main() {
//	Solution069MySqrt solution;
//	cout << solution.mySqrt1(2147395600) << endl;
//}