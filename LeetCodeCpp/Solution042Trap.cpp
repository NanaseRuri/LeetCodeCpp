#include "stdafx.h"

using namespace std;

class Solution042Trap {
public:
	int trap1(vector<int>& height) {
		int result = 0;
		int size = height.size();
		if (size < 3) {
			return result;
		}

		int preDifference = 0;
		stack<int> heightStack;
		stack<int> positionStack;

		for (int i = 0; i < size - 1; i++)
		{
			int difference = height[i] - height[i + 1];
			if (difference > 0) {
				heightStack.push(difference);
				positionStack.push(i);
			}
			else if (difference < 0 && heightStack.size() != 0) {
				difference = -difference;

				while (heightStack.size() != 0 && difference >= heightStack.top())
				{
					result += (i - positionStack.top()) * heightStack.top();
					difference -= heightStack.top();
					positionStack.pop();
					heightStack.pop();
				}
				if (difference > 0 && heightStack.size() != 0 && difference < heightStack.top()) {
					result += (i - positionStack.top()) * difference;
					heightStack.top() = heightStack.top() - difference;
				}
			}
		}

		return result;
	}

	int trap(vector<int>& height) {
		int heightSize = height.size();
		if (heightSize <= 2) {
			return 0;
		}

		int result = 0;
		int left = 0;
		int right = height.size() - 1;
		int leftMax = height[0];
		int rightMax = height[right];
		while (left < right)
		{
			if (leftMax < rightMax) {
				left++;
				leftMax = max(leftMax, height[left]);
				result += leftMax - height[left];
			}
			else {
				right--;
				rightMax = max(rightMax, height[right]);
				result += rightMax - height[right];
			}
		}
		return result;
	}


	int trap2(vector<int>& height) {
		int heightSize = height.size();

		vector<int> leftMax(heightSize);
		vector<int> rightMax(heightSize);

		leftMax[0] = height[0];
		for (int i = 1; i < heightSize; ++i) {
			leftMax[i] = max(leftMax[i - 1], height[i]);
		}

		rightMax[heightSize - 1] = height[heightSize - 1];
		for (int i = heightSize - 2; i >= 0; --i) {
			rightMax[i] = max(rightMax[i + 1], height[i]);
		}

		int result = 0;
		for (int i = 0; i < heightSize; ++i) {
			result += (min(leftMax[i], rightMax[i]) - height[i]);
		}

		return result;
	}
};

//int main() {
//	vector<int> nums{ 0,1,0,2,1,0,1,3,2,1,2,1 };
//	vector<int> nums1{ 4,2,0,3,2,5 };
//	Solution042Trap solution;
//	cout << solution.trap2(nums) << endl;
//	cout << solution.trap2(nums1) << endl;
//}
