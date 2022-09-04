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
		vector<string> result;
		unordered_map<string, int> restaurantIndexMap;

		int list1Size = list1.size();
		for (int i = 0; i < list1Size; i++)
		{
			restaurantIndexMap.emplace(pair<string, int>{ list1[i], i });
		}

		int minIndexSum = INT32_MAX;

		int list2Szie = list2.size();
		for (int i = 0; i < list2Szie; i++)
		{
			if (restaurantIndexMap.find(list2[i]) != restaurantIndexMap.end()) {
				int index = i + restaurantIndexMap[list2[i]];
				if (index < minIndexSum) {
					result.clear();
					result.push_back(list2[i]);
					minIndexSum = index;
				}
				else if (index == minIndexSum) {
					result.push_back(list2[i]);
				}
			}
		}

		return result;
	}
};