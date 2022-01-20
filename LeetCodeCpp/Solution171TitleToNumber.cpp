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
class Solution171TitleToNumber {
public:
	int titleToNumber(string columnTitle) {
		int result = 0;
		int aMinus1 = 'A' - 1;
		for (auto& c : columnTitle) {
			result *= 26;
			result += c - aMinus1;
		}

		return result;
	}
};