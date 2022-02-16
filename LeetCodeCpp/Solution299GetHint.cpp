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

class Solution299GetHint
{
public:
	string getHint(string secret, string guess) {
		vector<int> secretNums(10);
		vector<int> guessNums(10);

		int secretLength = secret.length();
		int a = 0;
		for (size_t i = 0; i < secretLength; i++)
		{
			if (secret[i] == guess[i]) {
				a += 1;
			}
			else {
				secretNums[secret[i] - '0'] += 1;
				guessNums[guess[i] - '0'] += 1;
			}
		}

		int b = 0;
		for (int i = 0; i < 10; i++)
		{
			b += min(secretNums[i], guessNums[i]);
		}

		return to_string(a) + "A" + to_string(b) + "B";
	}
};

//int main() {
//	Solution299GetHint solution;
//	solution.getHint("1123", "0111");
//}