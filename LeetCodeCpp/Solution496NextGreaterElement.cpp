#include "stdafx.h"

class Solution496NextGreaterElement {
public:
	vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> nextElementMap;
		stack<int> singleStack;
		for (int i = nums2.size() - 1; i >= 0; i--) {
			int num = nums2[i];
			while (!singleStack.empty() && num >= singleStack.top())
			{
				singleStack.pop();
			}

			nextElementMap[num] = singleStack.empty() ? -1 : singleStack.top();
			singleStack.push(num);
		}

		int nums1Size = nums1.size();
		vector<int> result(nums1Size);

		for (int i = 0; i < nums1Size; i++)
		{
			result[i] = nextElementMap[nums1[i]];
		}
		return result;
	}
};
