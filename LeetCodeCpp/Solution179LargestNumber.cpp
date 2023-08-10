#include "stdafx.h"

using namespace std;
class Solution179LargestNumber {
private:
public:
	string largestNumber(vector<int>& nums) {
		sort(nums.begin(), nums.end(), [](const int& x, const int& y) {
			long long sx = 10;
			long long sy = 10;
			while (sx < x)
			{
				sx *= 10;
			}while (sy < y) {
				sy *= 10;
			}
			return sy * x + y > sx * y + x;
			});

		if (nums[0] == 0) {
			return "0";
		}
		else {
			string result;
			for (auto& num : nums)
			{
				result += to_string(num);
			}
			return result;
		}
	}
};

//int main() {
//	vector<int> nums{ 3,30,34,5,9 };
//	Solution179LargestNumber solution;
//	solution.largestNumber(nums);
//}
