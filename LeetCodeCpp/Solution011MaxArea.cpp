#include "stdafx.h"

using namespace std;
class Solution011MaxArea {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int max = 0;
		int current;
		while (left < right) {
			if (height[left] < height[right]) {
				current = height[left] * (right - left);
				if (current > max) {
					max = current;
				}
				left++;
			}
			else {
				current = height[right] * (right - left);
				if (current > max) {
					max = current;
				}
				right--;
			}
		}
		return max;
	}
};
