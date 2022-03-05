#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"
#include "TreeNode.h"
#include "Node.h"
#include <set>

using namespace std;

using ll = long long;
constexpr ll Pow[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000, 10000000000, 100000000000, 1000000000000, 10000000000000, 100000000000000, 1000000000000000, 10000000000000000, 100000000000000000 };

class Solution564NearestPalindromic
{
	ll GetPld(const ll& num) {
		string str = to_string(num);
		int strLength = str.length();

		for (int left = 0, right = strLength - 1; left < right; left++, right--)
		{
			str[right] = str[left];
		}

		return stoll(str);
	}
public:
	string nearestPalindromic(string s) {
		ll current = stoll(s);
		if (current == 11) {
			return "9";
		}

		int sLength = s.length();
		ll result1 = current;
		ll result2 = current;

		int powValue = 0;
		while (result1 >= current) {
			result1 = GetPld(current - Pow[powValue]);
			++powValue;
		}
		powValue = 0;
		while (result2 <= current) {
			result2 = GetPld(current + Pow[powValue]);
			++powValue;
		}

		if (result2 - current < current - result1) {
			return to_string(result1);
		}
		else {
			return to_string(result2);
		}
	}
};
