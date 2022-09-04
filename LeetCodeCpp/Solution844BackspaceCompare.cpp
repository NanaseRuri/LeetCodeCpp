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

class Solution876MiddleNode
{
public:
	bool backspaceCompare(string s, string t) {
		int i = s.length() - 1;
		int j = t.length() - 1;

		int skipS = 0;
		int skipT = 0;

		while (i >= 0 || j >= 0)
		{
			while (i >= 0) {
				if (s[i] == '#') {
					skipS++;
					i--;
				}
				else if (skipS > 0) {
					skipS--;
					i--;
				}
				else {
					break;
				}
			}

			while (j >= 0) {
				if (t[j] == '#') {
					skipT++;
					j--;
				}
				else if (skipT > 0) {
					skipT--;
					j--;
				}
				else {
					break;
				}
			}

			if (i >= 0 && j >= 0) {
				if (s[i] != t[j]) {
					return false;
				}
			}
			else {
				if (i >= 0 || j >= 0) {
					return false;
				}
			}

			i--;
			j--;
		}
		return true;
	}
};


//int main() {
//	Solution876MiddleNode solution;
//	solution.backspaceCompare("a##c", "#a#c");
//}