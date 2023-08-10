#include "stdafx.h"

using namespace std;

class Solution278FirstBadVersion
{
public:

	bool isBadVersion(int version);

	int firstBadVersion(int n) {
		int firstVersion = 1;
		int middle;
		while (firstVersion <= n)
		{
			middle = firstVersion + (n - firstVersion) / 2;
			if (isBadVersion(middle)) {
				n = middle - 1;
			}
			else {
				firstVersion = middle + 1;
			}
		}
		return firstVersion;
	}
};
