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

class Solution1790AreAlmostEqual
{
public:
	bool areAlmostEqual(string s1, string s2) {
		int s1Size = s1.size();

		vector<int> differenceIndex;

		for (int i = 0; i < s1Size; i++) {
			if (s1[i] != s2[i]) {
				differenceIndex.push_back(i);
				if (differenceIndex.size() > 2) {
					return false;
				}
			}
		}

		return differenceIndex.size() == 0 ||
			(differenceIndex.size() == 2 && s1[differenceIndex[0]] == s2[differenceIndex[1]] && s1[differenceIndex[1]] == s1[differenceIndex[0]]);
	}
};
