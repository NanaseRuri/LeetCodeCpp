#include "stdafx.h"

using namespace std;

class Solution393ValidUtf8
{
public:
	bool validUtf8(vector<int>& data) {
		int dataSize = data.size();
		int left = 0;
		while (left < dataSize)
		{
			int begin1Count = GetBegin1Count(data[left]);

			if (begin1Count == 0) {
				++left;
			}
			else if (begin1Count >= 2 && begin1Count <= 4) {
				if (left + begin1Count > dataSize) {
					return false;
				}

				for (int i = 1; i < begin1Count; i++) {
					if (!valid(data[left + i])) {
						return false;
					}
				}
				left = left + begin1Count;
			}
			else {
				return false;
			}
		}

		return true;
	}

	int mask1 = (1 << 7) + (1 << 6);
	int mask2 = 1 << 7;
	bool valid(int num) {
		return (num & mask1) == mask2;
	}

	int GetBegin1Count(int num) {
		int begin1Count = 0;
		int begin1 = 1 << 7;
		while ((num & begin1) != 0) {
			begin1 >>= 1;
			begin1Count++;
		}
		unordered_map<int, int> m;		
		return begin1Count;
	}
};

//int main() {
//	Solution393ValidUtf8 solution;
//
//	vector<int> data1{ 197,130,1 };
//	vector<int> data2{ 235,140,4 };
//	vector<int> data3{ 145 };
//	cout << solution.validUtf8(data1) << endl;
//	cout << solution.validUtf8(data2) << endl;
//	cout << solution.validUtf8(data3) << endl;
//}
