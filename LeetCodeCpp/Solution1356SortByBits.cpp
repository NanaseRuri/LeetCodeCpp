#include "stdafx.h"

using namespace std;

class Solution1356SortByBits
{
public:
	vector<int> sortByBits(vector<int>& arr) {
		unordered_map<int, vector<int>> bitNumsMap;
		for (auto& num : arr)
		{
			bitNumsMap[GetBits(num)].push_back(num);
		}

		vector<int> result;
		for (int i = 0; i <= 14; i++) {
			if (bitNumsMap.find(i) != bitNumsMap.end()) {
				sort(bitNumsMap[i].begin(), bitNumsMap[i].end());
				for (auto it = bitNumsMap[i].begin(); it != bitNumsMap[i].end(); it++) {
					result.push_back(*it);
				}
			}
		}

		return result;
	}

	int GetBits(int n) {
		int result = 0;
		while (n > 0)
		{
			n = n & (n - 1);
			result++;
		}
		return result;
	}

	vector<int> sortByBits1(vector<int>& arr) {
		vector<int> result(arr);
		sort(result.begin(), result.end(), [&](int x, int y) {
			int xBits = GetBits(x);
			int yBits = GetBits(y);
			if (xBits < yBits) {
				return true;
			}
			else if (xBits > yBits) {
				return false;
			}
			else {
				return x < y;
			}
		});

		return result;
	}
};
