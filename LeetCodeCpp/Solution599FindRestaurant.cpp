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

class Solution599FindRestaurant {
public:
	vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
		unordered_map<string, int> indexMap;
		for (int i = 0; i < list1.size(); i++) {
			indexMap[list1[i]] = i;
		}

		vector<string> result;
		int indexSum = INT32_MAX;
		for (int i = 0; i < list2.size(); i++) {
			if (indexMap.count(list2[i]) > 0) {
				int j = indexMap[list2[i]];
				if (i + j < indexSum) {
					result.clear();
					result.push_back(list2[i]);
					indexSum = i + j;
				}
				else if (i + j == indexSum) {
					result.push_back(list2[i]);
				}
			}
		}
		return result;
	}
};