#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Solution026RemoveDuplicates {
public:
	int removeDuplicates(vector<int>& nums) {
		int size = nums.size();
		if (size == 0) {
			return 0;
		}

		int left = 0;
		int right = 1;
		while (right < size) {
			if (nums[right - 1] != nums[right]) {
				nums[left] = nums[right - 1];
				left++;
			}
			right++;
		}
		return left;
	}
};

//int main() {
//	Solution026RemoveDuplicates solution;
//	//vector<int> temp = { 0,0,1,1,1,2,2,3,3,4 };
//	vector<int> temp = { 1,1 };
//	solution.removeDuplicates(temp);
//
//	for (int i = 0; i < temp.size(); i++)
//	{
//		cout << temp[i] << '\t';
//	}
//}