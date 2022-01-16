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

class Solution152MaxProduct
{
public:
	string reverseWords(string s) {
		int left = s.size();
		int right = s.size();

		string result;
		for (int i = left - 1; i >= 0; i--)
		{
			if (s[i] == ' ') {
				if (left != right) {
					result += s.substr(left, right - left) + ' ';
				}
				left = i;
				right = i;
			}
			else {
				left--;
			}
		}

		if (left != right) {
			result += s.substr(left, right - left);
		}
		if (result[result.length() - 1] == ' ') {
			result.erase(result.length() - 1);
		}

		return result;
	}
};

//int main() {
//	Solution152MaxProduct solution;
//	cout << solution.reverseWords("the sky is blue") << endl;
//	cout << solution.reverseWords("  hello world  ") << endl;
//	cout << solution.reverseWords(" a good   example ") << endl;
//}