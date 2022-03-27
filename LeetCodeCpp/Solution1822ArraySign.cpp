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

class Solution1822ArraySign
{
public:
	int arraySign(vector<int>& nums) {
		int sign = 1;

		for (auto& num : nums)
		{
			if (num < 0) {
				sign = -sign;
			}
			else if (num == 0) {
				return 0;
			}
		}

		return sign;
	}
};
