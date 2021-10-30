#include <vector>

using namespace std;
class Solution004MedianOfTwoSortedArrays {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int nums1Size = nums1.size(),
			nums2Size = nums2.size(),
			totalSize = nums1Size + nums2Size,
			resultSize = totalSize % 2 == 0 ? 2 : 1;

		int nums1Index = 0, nums2Index = 0;

		if (resultSize == 2) {
			int result[2] = { 0,0 };
			int currentIndex = 0;
			int max = totalSize / 2;
			int count = 0;

			while (count <= max)
			{
				if (nums1Index < nums1Size && nums2Index < nums2Size) {
					if (nums1[nums1Index] <= nums2[nums2Index]) {
						result[currentIndex] = nums1[nums1Index];
						nums1Index++;
					}
					else {
						result[currentIndex] = nums2[nums2Index];
						nums2Index++;
					}
				}
				else if (nums1Index < nums1Size) {
					result[currentIndex] = nums1[nums1Index];
					nums1Index++;
				}
				else
				{
					result[currentIndex] = nums2[nums2Index];
					nums2Index++;
				}
				currentIndex = (currentIndex + 1) % 2;
				count++;
			}
			return ((double)result[0] + result[1]) / 2;
		}
		else {
			int result = 0;
			int max = totalSize / 2;
			int count = 0;

			while (count <= max)
			{
				if (nums1Index < nums1Size && nums2Index < nums2Size) {
					if (nums1[nums1Index] <= nums2[nums2Index]) {
						result = nums1[nums1Index];
						nums1Index++;
					}
					else {
						result = nums2[nums2Index];
						nums2Index++;
					}
				}
				else if (nums1Index < nums1Size) {
					result = nums1[nums1Index];
					nums1Index++;
				}
				else
				{
					result = nums2[nums2Index];
					nums2Index++;
				}

				count++;
			}
			return result;
		}
	}
	double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size(), n = nums2.size();
		int k = (m + n) / 2;
		if ((m + n) % 2 == 0) {
			return (findKth(nums1, nums2, 0, 0, m, n, k) + findKth(nums1, nums2, 0, 0, m, n, k + 1)) / 2;
		}
		else {
			return findKth(nums1, nums2, 0, 0, m, n, k + 1);
		}
	}

	double findKth(vector<int>& arr1, vector<int>& arr2, int start1, int start2, int len1, int len2, int k) {
		// 保证arr1是较短的数组
		if (len1 > len2) {
			return findKth(arr2, arr1, start2, start1, len2, len1, k);
		}
		if (len1 == 0) {
			return arr2[start2 + k - 1];
		}
		if (k == 1) {
			return min(arr1[start1], arr2[start2]);
		}
		int p1 = min(k / 2, len1);
		int p2 = k - p1;
		if (arr1[start1 + p1 - 1] < arr2[start2 + p2 - 1]) {
			return findKth(arr1, arr2, start1 + p1, start2, len1 - p1, len2, k - p1);
		}
		else if (arr1[start1 + p1 - 1] > arr2[start2 + p2 - 1]) {
			return findKth(arr1, arr2, start1, start2 + p2, len1, len2 - p2, k - p2);
		}
		else {
			return arr1[start1 + p1 - 1];
		}
	}
};

//int main() {
//	vector<int> nums1;
//	vector<int> nums2;
//	nums1.push_back(1);
//	nums1.push_back(3);
//	nums1.push_back(4);
//	nums2.push_back(2);
//
//	Solution004MedianOfTwoSortedArrays solution;
//
//	solution.findMedianSortedArrays1(nums1, nums2);
//}