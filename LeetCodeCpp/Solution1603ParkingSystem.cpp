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

class ParkingSystem {
public:
	int _maxCar[3];
	int _currentCar[3];

	ParkingSystem(int big, int medium, int small) {		
		_maxCar[0] = big;
		_maxCar[1] = medium;
		_maxCar[2] = small;

		_currentCar[0] = 0;
		_currentCar[1] = 0;
		_currentCar[2] = 0;
	}

	bool addCar(int carType) {
		if (_currentCar[carType - 1] == _maxCar[carType - 1]) {
			return false;
		}
		else {
			++_currentCar[carType - 1];
			return true;
		}
	}
};