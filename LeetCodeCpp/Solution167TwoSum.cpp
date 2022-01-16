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
class Solution167TwoSum {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		int left = 0;
		int right = numbers.size() - 1;
		while (left < right)
		{
			int sum = numbers[left] + numbers[right];
			if (sum == target) {
				return vector<int>{left + 1, right + 1};
			}
			else if (sum < target) {
				left++;
			}
			else {
				right--;
			}
		}

		return vector<int>();
	}
};