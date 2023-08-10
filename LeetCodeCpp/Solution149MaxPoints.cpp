#include "stdafx.h"

using namespace std;

class Solution149MaxPoints
{
public:
	/// <summary>
	/// �����Լ��
	/// </summary>
	/// <returns></returns>
	int Gcd(int a, int b) {
		return b ? Gcd(b, a % b) : a;
	}

	int maxPoints(vector<vector<int>>& points) {
		int n = points.size();
		if (n <= 2) {
			return n;
		}

		int result = 0;
		for (int i = 0; i < n; i++) {
			if (result >= n - i || result > n / 2) {
				break;
			}
			unordered_map<int, int> pointMap;
			for (int j = i + 1; j < n; j++)
			{
				int x = points[i][0] - points[j][0];
				int y = points[i][1] - points[j][1];

				if (x == 0) {
					y = 1;
				}
				else if (y == 0) {
					x = 1;
				}
				else {
					// ͬһ����
					if (y < 0) {
						x = -x;
						y = -y;
					}
					int gcd = Gcd(abs(x), abs(y));
					x /= gcd;
					y /= gcd;
				}
				pointMap[y + x * 20001]++;
			}
			for (auto pair : pointMap)
			{
				result = max(result, pair.second + 1);
			}
		}

		return result;
	}
};
