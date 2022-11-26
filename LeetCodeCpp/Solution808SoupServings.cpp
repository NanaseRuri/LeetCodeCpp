#include "stdafx.h"

class Solution808SoupServings
{
public:
	map<tuple<int, int>, double> _probabilityMap;

	double soupServings(int n) {
		_probabilityMap = {  };
		return soupServings(n, n);
	}

	double soupServings(int a, int b) {
		auto currentTuple = make_tuple(a, b);
		if (_probabilityMap.find(currentTuple) != _probabilityMap.end()) {
			return _probabilityMap[currentTuple];
		}
		queue<int> myQueue;
		if (a <= 0 && b <= 0) {
			return 0.5;
		}
		else if (a <= 0) {
			return 1;
		}
		else if (b <= 0) {
			return 0;
		}
		else {
			double result = soupServings(a - 100, b) / 4 + soupServings(a - 75, b - 25) / 4 +
				soupServings(a - 50, b - 50) / 4 + soupServings(a - 25, b - 75) / 4;
			_probabilityMap[currentTuple] = result;
			return result;
		}
	}
};

int main()
{
	Solution808SoupServings solution;
	solution.soupServings(660295675);
}