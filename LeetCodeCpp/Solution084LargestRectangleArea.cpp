#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>\

using namespace std;

class Solution084LargestRectangleArea
{
public:
	int largestRectangleArea(vector<int>& heights) {
		int maxArea = 0;
		int heightsSize = heights.size();

		int currentCount;
		for (size_t i = 0; i < heightsSize; i++)
		{
			currentCount = 1;
			for (int j = i - 1; j >= 0; j--)
			{
				if (heights[j] <= heights[i]) {
					break;
				}
				currentCount++;
			}

			for (int j = i + 1; j < heightsSize; j++)
			{
				if (heights[j] < heights[i]) {
					break;
				}
				currentCount++;
			}

			maxArea = max(maxArea, currentCount * heights[i]);
		}

		return maxArea;
	}

	int largestRectangleArea1(vector<int>& heights) {
		stack<int> myStack;
		int heightsSize = heights.size();

		int maxArea = 0;
		for (int i = 0; i < heightsSize; i++)
		{
			if (myStack.empty() || heights[i] > heights[myStack.top()]) {
				myStack.push(i);
			}
			else {
				while (!myStack.empty() && heights[i] <= heights[myStack.top()])
				{
					int lastHeight = heights[myStack.top()];
					myStack.pop();
					maxArea = max(maxArea, lastHeight * (i - (myStack.empty() ? -1 : myStack.top()) - 1));
				}
				myStack.push(i);
			}
		}

		int lengthOnRight = 0;
		while (!myStack.empty())
		{
			int lastIndex = myStack.top();
			int lastHeight = heights[lastIndex];
			myStack.pop();
			int lengthOnLeft = lastIndex - (myStack.empty() ? -1 : myStack.top());
			maxArea = max(maxArea, lastHeight * (lengthOnRight + lengthOnLeft));
			lengthOnRight += lengthOnLeft;
		}
		return maxArea;
	}
};

//int main() {
//	vector<int > nums1{ 3,6,5,7,4,8,1,0 };
//	vector<int > nums2{ 2,4 };
//	vector<int > nums3{ 2,4,2 };
//	vector<int > nums4{ 2,4,2,2 };
//	vector<int > nums5{ 2,4,3 };
//	vector<int > nums6{ 2,3 };
//	Solution084LargestRectangleArea solution;
//	cout << solution.largestRectangleArea1(nums1) << endl;
//	cout << solution.largestRectangleArea1(nums2) << endl;
//	cout << solution.largestRectangleArea1(nums3) << endl;
//	cout << solution.largestRectangleArea1(nums4) << endl;
//	cout << solution.largestRectangleArea1(nums5) << endl;
//	cout << solution.largestRectangleArea1(nums6) << endl;
//}