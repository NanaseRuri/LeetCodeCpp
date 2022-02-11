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

class Solution233CountDigitOne
{
public:
	int countDigitOne(int n) {
		int low = 0;
		int high = n / 10;
		int result = 0;
		long long bulk = 1;
		int cur = n % 10;

		while (high != 0 || cur != 0)
		{
			if (cur == 0) {
				result += high * bulk;
			}
			else if (cur == 1) {
				result += high * bulk + low + 1;
			}
			else {
				result += (high + 1) * bulk;
			}

			low += cur * bulk;
			cur = high % 10;
			high /= 10;
			bulk *= 10;
		}
		return result;
	}
};

//int main() {
//	Solution233CountDigitOne solution;
//	cout << solution.countDigitOne(13) << endl;
//	cout << solution.countDigitOne(21) << endl;
//	cout << solution.countDigitOne(20) << endl;
//	cout << solution.countDigitOne(232) << endl;
//	cout << solution.countDigitOne(222) << endl;
//	cout << solution.countDigitOne(212) << endl;
//	cout << solution.countDigitOne(2112) << endl;
//}