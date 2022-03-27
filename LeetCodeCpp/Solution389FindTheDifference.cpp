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

class Solution389FindTheDifference
{
public:
    char findTheDifference(string s, string t) {
		int result = 0;
		for (auto& c:s)
		{
			result ^= c;
		}
		for (auto& c:t)
		{
			result ^= c;
		}

		return result;
    }
};