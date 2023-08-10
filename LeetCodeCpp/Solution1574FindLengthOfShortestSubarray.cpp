#include "stdafx.h"

using namespace std;

class Solution1574FindLengthOfShortestSubarray
{
public:
	int findLengthOfShortestSubarray(vector<int>& arr) {
		int n = arr.size();
		int right = n - 1;

		while (right > 0 && arr[right] >= arr[right - 1]) {
			right--;
		}

		if (right == 0) {
			return 0;
		}

		// ����������Ҳ�
		int result = right;
		for (int left = 0; left < n; left++) {
			// ɾ���м�Ŀɵõ���������
			while (right < n && arr[right] < arr[left]) {
				right++;
			}

			result = min(result, right - left - 1);

			if (left + 1 < n && arr[left] > arr[left + 1]) {
				break;
			}
		}

		return result;
	}
};
