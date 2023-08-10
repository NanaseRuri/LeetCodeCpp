#include "stdafx.h"

using namespace std;
class Solution2363MergeSimilarItems
{
public:
	vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
		unordered_map<int, int> itemsMap;
		for (auto& items : items1)
		{
			itemsMap[items[0]] += items[1];
		}
		for (auto& items : items2)
		{
			itemsMap[items[0]] += items[1];
		}

		vector<vector<int>> result;
		for (auto& keyPair : itemsMap) {
			result.push_back(vector<int>{keyPair.first, keyPair.second});
		}

		sort(result.begin(), result.end(), [](vector<int>& x, vector<int>& y)->bool {
			return x[0] < y[0];
			});

		return result;
	}
};
