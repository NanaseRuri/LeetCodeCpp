#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>

using namespace std;

class Solution031NextPermutation {
private:
	/// <summary>
	/// 建一个大根堆，用于将数组从小到大排序
	/// </summary>
	/// <param name = "nums">数组< / param>
	///	<param name = "head">头结点< / param>
	///	<param name = "left">< / param>
	///	<param name = "right">< / param>
	void BuildHeap(vector<int>& nums, int startIndex, int size) {
		for (int i = size / 2; i > 0; i--)
		{
			Adjust(nums, startIndex, i, size);
		}
	}

	void Adjust(vector<int>& nums, int startIndex, int index, int size) {
		if (2 * index == size) {
			if (nums[startIndex + 2 * index] > nums[startIndex + index]) {
				int temp = nums[startIndex + 2 * index];
				nums[startIndex + 2 * index] = nums[startIndex + index];
				nums[startIndex + index] = temp;
			}
		}
		else {
			int parentIndex = startIndex + index;
			int parentValue = nums[parentIndex];
			if (nums[startIndex + 2 * index] > parentValue && nums[startIndex + 2 * index] >= nums[startIndex + 2 * index + 1]) {
				nums[parentIndex] = nums[startIndex + 2 * index];
				nums[startIndex + 2 * index] = parentValue;
				if (4 * index <= size) {
					Adjust(nums, startIndex, 2 * index, size);
				}
			}
			else {
				if (nums[startIndex + 2 * index + 1] > parentValue && nums[startIndex + 2 * index + 1] >= nums[startIndex + 2 * index]) {
					nums[parentIndex] = nums[startIndex + 2 * index + 1];
					nums[startIndex + 2 * index + 1] = parentValue;
					if (parentIndex + 4 * index + 2 <= size) {
						Adjust(nums, startIndex, 2 * index + 1, size);
					}
				}
			}
		}
	}

	void HeapSort(vector<int>& nums, int left, int heapSize)
	{
		if (heapSize <= 1) {
			return;
		}

		BuildHeap(nums, left, heapSize);

		for (int i = heapSize; i > 1; i--)
		{
			int maxValue = nums[left + 1];
			nums[left + 1] = nums[left + i];
			nums[left + i] = maxValue;
			if (i > 2) {
				Adjust(nums, left, 1, i - 1);
			}			
		}
	}

public:
	void nextPermutation(vector<int>& nums) {
		int numSize = nums.size();

		if (numSize <= 1) {
			return;
		}

		for (int i = numSize - 2; i >= 0; i--)
		{
			for (int j = numSize - 1; j > i; j--)
			{
				if (nums[i] < nums[j]) {
					int temp = nums[j];
					nums[j] = nums[i];
					nums[i] = temp;
					//sort(nums.begin() + i + 1, nums.end());
					HeapSort(nums, i, nums.size() - i - 1);
					return;
				}
			}
		}

		// 没有发生过交换则需要将数组沿中间镜像替换以获得最小值
		int left = 0;
		int right = numSize - 1;
		while (left < right)
		{
			int temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
			left++;
			right--;
		}
	}
};

//int main() {
//	Solution031NextPermutation solution;
//	vector<int> nums1{ 1,2,3 };
//	vector<int> nums2{ 3,2,1 };
//	vector<int> nums3{ 1,2,3,4 };
//	vector<int> nums4{ 1,4,3,2 };
//	vector<int> nums5{ 2,3,1 };
//	vector<int> nums6{ 4,2,0,2,3,2,0 };
//	vector<int> nums7{ 4,8,8,8,9,7,7,6,4,3 };
//	solution.nextPermutation(nums1);
//	solution.nextPermutation(nums2);
//	solution.nextPermutation(nums3);
//	solution.nextPermutation(nums4);
//	solution.nextPermutation(nums5);
//	solution.nextPermutation(nums6);
//	solution.nextPermutation(nums7);
//} 