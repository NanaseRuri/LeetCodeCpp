#include "stdafx.h"

using namespace std;

class Solution241DiffWaysToCompute
{
public:
	vector<int> diffWaysToCompute(string& expression) {
		vector<int> vector1;
		vector<int> vector2;
		vector<int> result;
		int flag = 0;
		int n = expression.size();
		for (int i = 0; i < n; i++)
		{
			if (!isdigit(expression[i])) {
				flag = 1;
				string leftString = string(expression, 0, i);
				string rightString = string(expression, i + 1, n);
				vector1 = diffWaysToCompute(leftString);
				vector2 = diffWaysToCompute(rightString);

				for (auto& v1 : vector1)
				{
					for (auto& v2 : vector2)
					{
						if (expression[i] == '+') {
							result.push_back(v1 + v2);
						}
						else if (expression[i] == '-') {
							result.push_back(v1 - v2);
						}
						else if (expression[i] == '*') {
							result.push_back(v1 * v2);
						}
					}
				}
			}
		}
		if (flag == 0) {
			return vector<int>{stoi(expression)};
		}
		else {
			return result;
		}
	}
};
