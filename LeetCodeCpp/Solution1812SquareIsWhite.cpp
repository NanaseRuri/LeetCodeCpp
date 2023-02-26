#include "stdafx.h"

using namespace std;

class Solution1812SquareIsWhite
{
public:
	bool squareIsWhite(string coordinates) {
		return ((coordinates[0] - 'a') % 2) ^ ((coordinates[1] - '1') % 2);
	}
};
