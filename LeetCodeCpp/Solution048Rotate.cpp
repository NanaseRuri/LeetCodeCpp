#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution049GroupAnagrams {
public:
	void rotate(vector<vector<int>>& matrix) {
		int length = matrix.size() - 1;

		int index = 0;
		for (int i = 0; i < length; i += 2)
		{
			for (int j = 0; j < length - i; j++)
			{
				int temp = matrix[index][index + j];
				matrix[index][index + j] = matrix[length - index - j][index];
				matrix[length - index - j][index] = matrix[length - index][length - index - j];
				matrix[length - index][length - index - j] = matrix[j + index][length - index];
				matrix[j + index][length - index] = temp;
			}
			index++;
		}
	}
};

//int main() {
//	vector<vector<int>> nums
//	{
//		{1,2,3},
//		{4,5,6},
//		{7,8,9},
//	};
//	vector<vector<int>> nums1
//	{
//		{5,1,9,11},
//		{2,4,8,10},
//		{13,3,6,7},
//		{15,14,12,16},
//	};
//
//	Solution048Rotate solution;
//	solution.rotate(nums);
//	solution.rotate(nums1);
//}