#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

void AdjustHeap(vector<int>& nums, int index, int length) {
	int temp = nums[index];
	for (int i = index * 2 + 1; i < length; i = i * 2 + 1) {
		if (i + 1 < length && nums[i] > nums[i + 1]) {
			++i;
		}
		if (nums[i] < temp) {
			nums[index] = nums[i];
			index = i;
		}
		else {
			break;
		}
	}
	nums[index] = temp;
}

void BuildHeap(vector<int>& nums) {
	int numsSize = nums.size();

	for (int i = numsSize / 2 - 1; i >= 0; i--) {
		AdjustHeap(nums, i, numsSize);
	}
}

//int main() {
//	vector<string> input;
//	int orderCount;
//	int maxGetOrderCount;
//
//	cin >> orderCount >> maxGetOrderCount;
//
//	if (orderCount <= maxGetOrderCount) {
//		cout << 1;
//		for (int i = 1; i <= orderCount; ++i) {
//			cout << ' ' << i;
//		}
//	}
//	else {
//		vector<int> minHeap(maxGetOrderCount);
//		for (int i = 0; i < maxGetOrderCount; i++) {
//			cin >> minHeap[i];
//		}
//
//		BuildHeap(minHeap);
//		for (int i = maxGetOrderCount; i < orderCount; i++) {
//			cin >> minHeap[0];
//			AdjustHeap(minHeap, 0, maxGetOrderCount);
//		}
//	}
//}
