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

class Solution2038WinnerOfGame
{
public:
	bool winnerOfGame(string colors) {
		int freq[2] = { 0,0 };
		char cur = 'C';
		int count = 0;
		for (char& c : colors)
		{
			if (c != cur) {
				cur = c;
				count = 1;
			}
			else {
				++count;
				if (count >= 3) {
					++freq[cur - 'A'];
				}
			}
		}

		return freq[0] > freq[1];
	}
};