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

using namespace std;

class Solution125IsPalindrome
{
public:
	bool isPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;

		while (left < right)
		{
			while (left < right && !isalnum(s[left])) {
				left++;
			}
			if (left >= right) {
				break;
			}
			while (left < right && !isalnum(s[right])) {
				right--;
			}
			if (left >= right) {
				break;
			}
			if (s[left] != s[right]) {
				if (((s[left] >= 'A' && s[left] <= 'Z') || (s[left] >= 'a' && s[left] <= 'z')) &&
					(s[right] >= 'A' && s[right] <= 'Z') || (s[right] >= 'a' && s[right] <= 'z'))
				{
					if (s[left] + 32 != s[right] && s[left] != s[right] + 32) {
						return false;
					}
				}
				else {
					return false;
				}
			}
			left++;
			right--;
		}
		
		return true;
	}
};

//int main() {
//	string s = "A man, a plan, a canal: Panama";
//	string s1 = "OP";
//	string s2 = "0P";
//	Solution125IsPalindrome solution;
//	cout << solution.isPalindrome(s) << endl;
//	cout << solution.isPalindrome(s1) << endl;
//	cout << solution.isPalindrome(s2) << endl;
//}