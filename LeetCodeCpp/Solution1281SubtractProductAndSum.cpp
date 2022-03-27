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

class Solution1281SubtractProductAndSum
{
public:
	int subtractProductAndSum(int n) {
		int multipleResult = 1;
		int sumResult = 0;
		int remainder;

		while (n > 0)
		{
			remainder = n % 10;
			multipleResult *= remainder;
			sumResult *= remainder; 
			n /= 10;
		}

		return multipleResult - sumResult;
	}
};
