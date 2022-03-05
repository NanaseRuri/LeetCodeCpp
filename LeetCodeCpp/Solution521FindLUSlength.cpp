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

class Solution521FindLUSlength
{
public:
	int findLUSlength(string a, string b) {
		return a == b ? -1 : max(a.length(), b.length());
	}
};
