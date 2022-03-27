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

class Solution1768MergeAlternately
{
public:
	string mergeAlternately(string word1, string word2) {
		int word1Size = word1.size();
		int word2Size = word2.size();

		string result;
		result.resize(word1Size + word2Size);
		int index = 0;
		while (index < word1Size && index < word2Size)
		{
			result[2 * index] = word1[index];
			result[2 * index + 1] = word2[index];
		}

		for (int i = index; i < word1Size; i++)
		{
			result[index + i] = word1[i];
		}

		for (int i = index; i < word2Size; i++)
		{
			result[index + i] = word2[i];
		}

		return result;
	}
};
