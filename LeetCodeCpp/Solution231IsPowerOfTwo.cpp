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

class Solution231IsPowerOfTwo
{
public:
	bool isPowerOfTwo(int n) {
		return n > 0 && (n & (n - 1)) == 0;
	}
};