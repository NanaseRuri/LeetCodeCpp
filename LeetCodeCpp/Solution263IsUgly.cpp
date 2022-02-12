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

class Solution263IsUgly
{
public:
	bool isUgly(int n) {
		if (n <= 0) {
			return false;
		}

		while (n % 2 == 0)
		{
			n /= 2;
		}
		while (n % 3 == 0)
		{
			n /= 3;
		}
		while (n % 5 == 0)
		{
			n /= 5;
		}

		return true;
	}
};