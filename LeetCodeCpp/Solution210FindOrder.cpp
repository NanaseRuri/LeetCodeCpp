#include "stdafx.h"


using namespace std;
class Solution210FindOrder {
private:
	bool _isValid;
	vector<int> _result;
	vector<vector<int>> _edges;
	vector<int> _courseChecked;

	void Dfs(int course) {
		_courseChecked[course] = 1;
		for (auto prerequisite : _edges[course])
		{
			if (_courseChecked[prerequisite] == 0) {
				Dfs(prerequisite);
				if (!_isValid) {
					return;
				}
			}
			else if (_courseChecked[prerequisite] == 1) {
				_isValid = false;
				return;
			}
		}
		_courseChecked[course] = 2;
		_result.push_back(course);
	}

public:
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
		_isValid = true;
		_result.clear();
		_edges.assign(numCourses, vector<int>());
		_courseChecked.assign(numCourses, 0);

		for (auto& prerequisite : prerequisites)
		{
			_edges[prerequisite[1]].push_back(prerequisite[0]);
		}

		for (int i = 0; i < numCourses; i++)
		{
			if (_courseChecked[i] == 0 && _isValid) {
				Dfs(i);
			}
		}

		if (_isValid) {
			reverse(_result.begin(), _result.end());
			return _result;
		}
		else {
			return vector<int>();
		}
	}
};

//int main() {
//	Solution210FindOrder solution;
//	vector<vector<int>> nums1{ { 1, 0} };
//	vector<vector<int> >nums2{ {1,0} ,{2,0},{3,1},{3,2} };
//
//	solution.findOrder(2, nums1);
//	solution.findOrder(4, nums2);
//}
