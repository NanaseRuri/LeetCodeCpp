#include "stdafx.h"

using namespace std;
class Solution001TwoSum {
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> temp(nums);
		sort(temp.begin(), temp.end());

		int left = 0;
		int right = temp.size() - 1;

		bool notFound = true;
		int sum;
		while (left < right)
		{
			sum = temp[left] + temp[right];
			if (sum == target)
			{
				break;
			}
			else if (sum < target)
			{
				left++;
			}
			else
			{
				right--;
			}
		}

		bool leftNotFound = true;
		bool rightNotFound = true;
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == temp[left] && leftNotFound)
			{
				leftNotFound = false;
				result.push_back(i);
			}
			else if (nums[i] == temp[right] && rightNotFound)
			{
				rightNotFound = false;
				result.push_back(i);
			}
			if (result.size() == 2)
			{
				return result;
			}
		}

		return vector<int>();
	}

	vector<int> twoSum1(vector<int>& nums, int target)
	{
		unordered_map<int, int> indexValueMap;

		int numsSize = nums.size();
		for (int i = 0; i < numsSize; i++)
		{
			if (indexValueMap.find(target - nums[i]) != indexValueMap.end()) {
				return vector<int>{i, indexValueMap[target - nums[i]]};
			}
			else {
				indexValueMap[nums[i]] = i;
			}
		}

		return vector<int>();
	}
};
