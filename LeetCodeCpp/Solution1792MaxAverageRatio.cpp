#include "stdafx.h"

class Solution1792MaxAverageRatio
{
	struct ClassPassInfo
	{
		int PassStudent;
		int TotalStudent;

		ClassPassInfo(int passStudent, int totalStudent) :PassStudent(passStudent), TotalStudent(totalStudent) {
		}
	};

public:
	double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
		auto cmp = [](ClassPassInfo* left, ClassPassInfo* right)->bool {
			return (long long)(right->TotalStudent + 1) * right->TotalStudent * (left->TotalStudent - left->PassStudent) <
				(long long)(left->TotalStudent + 1) * left->TotalStudent * (right->TotalStudent - right->PassStudent);
		};

		priority_queue <ClassPassInfo*, vector<ClassPassInfo*>, decltype(cmp)> myQueue(cmp);

		for (auto& classInfo : classes) {
			myQueue.push(new ClassPassInfo(classInfo[0], classInfo[1]));
		}

		for (int i = 0; i < extraStudents; i++) {
			auto topClass = myQueue.top();
			myQueue.pop();
			topClass->PassStudent += 1;
			topClass->TotalStudent += 1;
			myQueue.push(topClass);
		}

		double result = 0;

		int n = classes.size();
		for (int i = 0; i < n; i++) {
			auto topClass = myQueue.top();
			result += (double)topClass->PassStudent / topClass->TotalStudent;
			myQueue.pop();
			delete topClass;
		}

		return result / n;
	}
};

//int main() {
//	Solution1792MaxAverageRatio solution;
//
//	vector<vector<int>> classes1{
//		{1,2} ,{3,5},{2,2}
//	};
//
//	vector<vector<int>> classes2{
//		{2,4},{3,9},{4,5}, {2, 10}
//	};
//	solution.maxAverageRatio(classes1, 2);
//	solution.maxAverageRatio(classes2, 4);
//}