#include "stdafx.h"

using namespace std;

class Solution5968NumberOfBeams
{
public:
	int numberOfBeams(vector<string>& bank) {
		int result = 0;
		int row = bank.size();
		int col = bank[0].size();
		int lastBeam = 0;
		for (int i = 0; i < row; i++)
		{
			int currentBeam = 0;
			for (int j = 0; j < col; j++)
			{
				if (bank[i][j] == '1') {
					currentBeam++;
				}
			}
			if (currentBeam != 0) {
				result += currentBeam * lastBeam;
				lastBeam = currentBeam;
			}
		}

		return result;
	}
};

//int main() {
//	vector<string> bank{ "011001","000000","010100","001000" };
//	Solution5968NumberOfBeams solution;
//	solution.numberOfBeams(bank);
//}
