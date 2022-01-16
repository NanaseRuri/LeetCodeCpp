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
class Solution169MajorityElement {
public:
	int majorityElement(vector<int>& nums) {
		int majority = -1;
		int count = 0;

		for (auto &num : nums)
		{
			if (num == majority) {
				count++;
			}
			else if (--count < 0) {
				majority = num;
				count = 1;
			}
		}

		return majority;
	}
};