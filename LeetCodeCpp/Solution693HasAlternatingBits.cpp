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
#include <numeric>

class Solution693HasAlternatingBits {
public:
	bool hasAlternatingBits(int n) {
		int lastBitAnd = n & 1;
		n >>= 1;

		while (n > 0)
		{
			if ((n & 1) == lastBitAnd) {
				return false;
			}

			lastBitAnd = n & 1;
			n >>= 1;
		}
		return true;
	}
};