#include "stdafx.h"

using namespace std;

class Solution282AddOperators
{
private:
	int _numSize;
	int _target;
	vector<string> _result;
	void Dfs(string& num, string& currentString, int index, long long currentSum, long long lastNum) {
		if (index == _numSize) {
			if (currentSum == _target) {
				_result.push_back(currentString);
			}
			return;
		}

		// ��ǰ���ַ������ȼ�Ϊ�����������λ���±�
		int operatorIndex = currentString.size();

		// ������ʱλ����Ϊ����λ��������
		if (index > 0) {
			currentString.push_back(0);
		}

		long long currentNum = 0;
		// ����ǰ�� 0
		for (int j = index; j < _numSize && (j == index || num[index] != '0'); j++)
		{
			currentNum = currentNum * 10 + (num[j] - '0');
			currentString.push_back(num[j]);
			// ����һ��ʱ������������λ���� 0 λ������ţ�������ŻῪʼ
			if (index == 0) {
				Dfs(num, currentString, j + 1, currentNum, currentNum);
			}
			else {
				currentString[operatorIndex] = '+';
				// ����ֵΪ currentNum
				Dfs(num, currentString, j + 1, currentSum + currentNum, currentNum);
				currentString[operatorIndex] = '-';
				// ����ֵΪ -currentNum
				Dfs(num, currentString, j + 1, currentSum - currentNum, -currentNum);
				currentString[operatorIndex] = '*';
				// ����ֵΪ lastNum * currentNum
				Dfs(num, currentString, j + 1, currentSum - lastNum + lastNum * currentNum, lastNum * currentNum);
			}
		}

		currentString.resize(operatorIndex);
	}

public:
	vector<string> addOperators(string num, int target) {
		_result.clear();
		_numSize = num.length();
		_target = target;

		string expr;
		Dfs(num, expr, 0, 0, 0);
		return _result;
	}
};

//int main() {
//	Solution282AddOperators solution;
//	solution.addOperators("123", 6);
//	solution.addOperators("232", 8);
//	solution.addOperators("1015", 25);
//	solution.addOperators("00", 0);
//	solution.addOperators("3456237490", 9191);
//}
