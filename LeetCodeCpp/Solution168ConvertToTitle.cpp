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
#include "TreeNode.h"
#include "Node.h"
#include <set>

using namespace std;
class Solution168ConvertToTitle {
public:
	string convertToTitle(int columnNumber) {
		string result;
		while (columnNumber != 0)
		{
			--columnNumber;
			result += columnNumber % 26 + 'A';
			columnNumber /= 26;
		}
		reverse(result.begin(), result.end());
		return result;
	}
};

int main() {
	Solution168ConvertToTitle solution;
	solution.convertToTitle(701);
	solution.convertToTitle(28);
}