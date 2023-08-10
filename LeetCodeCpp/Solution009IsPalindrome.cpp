#include "stdafx.h"
class Solution009IsPalindrome {
public:
	bool isPalindrome(int x) {
		if (x < 0) {
			return false;
		}

		int temp[10];
		for (int i = 0; i < 10; i++) {
			temp[i] = -1;
		}
		int i = 0;

		while (x != 0)
		{
			temp[i] = x % 10;
			x /= 10;
			i++;
		}

		int left = 0;
		int right = 9;
		while (right >= 0 && temp[right] == -1) {
			right--;
		}

		while (left < right) {
			if (temp[left] != temp[right])
			{
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};
//
//int main() {
//	Solution009IsPalindrome solution;
//	solution.isPalindrome(10);
//}
