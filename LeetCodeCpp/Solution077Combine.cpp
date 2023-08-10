#include "stdafx.h"

using namespace std;

class Solution077Combine
{
private:
	vector<vector<int>>_result;
	vector<int> _currentResult;
	void Iteration(int startIndex, int n, int k) {
		if (_currentResult.size() + (n - startIndex + 1) < k) {
			return;
		}

		if (_currentResult.size() == k) {
			_result.push_back(vector<int>(_currentResult));
			return;
		}

		for (int i = startIndex; i < n; i++)
		{
			_currentResult.push_back(i + 1);
			Iteration(i + 1, n, k);
			_currentResult.pop_back();
		}
	}

public:
	vector<vector<int>> combine(int n, int k) {
		_result.clear();
		_currentResult.clear();

		Iteration(0, n, k);

		return _result;
	}
	vector<int> temp;
	vector<vector<int>> ans;

	vector<vector<int>> combine1(int n, int k) {
		// ��ʼ��
		// �� temp �� [0, k - 1] ÿ��λ�� i ����Ϊ i + 1���� [0, k - 1] �� [1, k]
		// ĩβ��һλ n + 1 ��Ϊ�ڱ�
		for (int i = 1; i <= k; ++i) {
			temp.push_back(i);
		}
		temp.push_back(n + 1);

		int j = 0;
		while (j < k) {
			ans.emplace_back(temp.begin(), temp.begin() + k);
			j = 0;
			// Ѱ�ҵ�һ�� temp[j] + 1 != temp[j + 1] ��λ�� t
			// ������Ҫ�� [0, t - 1] �����ڵ�ÿ��λ�����ó� [1, t]
			while (j < k && temp[j] + 1 == temp[j + 1]) {
				temp[j] = j + 1;
				++j;
			}
			// j �ǵ�һ�� temp[j] + 1 != temp[j + 1] ��λ��
			++temp[j];
		}
		return ans;
	}
};


//int main()
//{
//	int n = 4;
//	int k = 3;
//
//	Solution077Combine solution;
//	solution.combine(n, k);
//	solution.combine1(n, k);
//}
