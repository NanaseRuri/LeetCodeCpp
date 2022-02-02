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

class Solution201RangeBitwiseAnd
{
public:
	int rangeBitwiseAnd1(int left, int right) {
		int bit = 31;
		int result = 0;

		int leftBitAnd;
		int rightBitAnd;

		while (bit >= 0) {
			leftBitAnd = (left & (1 << bit));
			rightBitAnd = (right & (1 << bit));

			if (leftBitAnd != rightBitAnd) {
				break;
			}
			result += leftBitAnd;
			bit--;
		}
		return result;
	}

	int rangeBitwiseAnd(int left, int right) {
		while (left < right)
		{
			right &= (right - 1);
		}

		return right;
	}
};

//int main() {
//	Solution201RangeBitwiseAnd solution;
//	solution.rangeBitwiseAnd(5, 7);
//	solution.rangeBitwiseAnd(0, 0);
//	solution.rangeBitwiseAnd(1, 2147483647);
//}