#include "stdafx.h"

using namespace std;

class Solution119GetRow
{
public:
	vector<int> getRow(int rowIndex) {
		vector<int> preRow(rowIndex + 1, 1);
		vector<int> nextRow(rowIndex + 1, 1);

		for (int i = 1; i <= rowIndex; i++)
		{
			for (int j = 1; j < i; j++)
			{
				nextRow[j] = preRow[j - 1] + preRow[j];
			}
			swap(preRow, nextRow);
		}

		return preRow;
	}
};
