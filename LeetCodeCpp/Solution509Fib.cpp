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

class Solution509Fib
{
public:
	int fib(int n) {
		int f[2] = { 0,1 };

		for (int i = 2; i < n; i++)
		{
			f[i % 2] = f[0] + f[1];
		}

		return f[n % 2];
	}
};
