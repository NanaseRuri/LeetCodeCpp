#include "stdafx.h"

using ll = long long;
class Solution440FindKthNumber {
public:
	int GetSteps(int current, ll n) {
		int steps = 0;
		ll first = current;
		ll last = current;

		while (first <= n) {
			steps += min(last, n) - first + 1;
			first = first * 10;
			last = last * 10 + 9;
		}
		return steps;
	}

	int findKthNumber(int n, int k) {
		int current = 1;
		--k;
		while (k > 0)
		{
			int steps = GetSteps(current, n);
			if (steps <= k) {
				k -= steps;
				++current;
			}
			else {
				current *= 10;
				k--;
			}
		}
		return current;
	}
};
