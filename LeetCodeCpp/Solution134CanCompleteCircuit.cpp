#include "stdafx.h"

using namespace std;

class Solution134CanCompleteCircuit
{
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int gasSize = gas.size();
		int i = 0;

		while (i < gasSize)
		{
			int currentGas = 0;

			// ��������վ
			int count = 0;
			while (count < gasSize)
			{
				currentGas += gas[(i + count) % gasSize] - cost[(i + count) % gasSize];
				if (currentGas >= 0) {
					count++;
				}
				else {
					break;
				}
			}

			if (count == gasSize) {
				return i;
			}
			else {
				i = i + count + 1;
			}
		}
		return -1;
	}
};

//int main() {
//	vector<int> gas{ 1,2,3,4,5 };
//	vector<int> cost{ 3,4,5,1,2 };
//	Solution134CanCompleteCircuit solution;
//	solution.canCompleteCircuit(gas, cost);
//}
