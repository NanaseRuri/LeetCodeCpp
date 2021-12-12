#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <limits>
#include <stack>
#include <queue>
#include <unordered_set>
#include "ListNode.h"

using namespace std;

class Solution089GrayCode
{
public:
	vector<int> grayCode(int n) {
		vector<int> result{ 0 };

		for (int i = 0; i < n; i++)
		{
			int resultSize = result.size();
			for (int j = resultSize - 1; j >= 0; j--)
			{
				result.push_back(result[j] + (1 << i));
			}
		}
		return result;
	}
};

//int main() {
//	Solution089GrayCode solution;
//	solution.grayCode(2);
//	solution.grayCode(3);
//	solution.grayCode(4);
//}