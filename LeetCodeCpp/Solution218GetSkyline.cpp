#include "stdafx.h"

using namespace std;

class Solution218GetSkyline
{
	static int PairCompare(pair<int, int> left, pair<int, int> right) {
		if (left.first != right.first) {
			return left.first - right.first;
		}
		else {
			return left.second - right.second;
		}
	}

	static int IntCompare(int left, int right) {
		return right - left;
	}
public:
	vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
		auto cmp = [](const pair<int, int>& left, const pair<int, int>& right)->bool {return left.second < right.second; };
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> buildingQueue(cmp);

		// ���������ߵ����꣬��������Ȼ�������ұ仯�ĸ߶�
		vector<int> boundaries;
		for (auto& building : buildings)
		{
			boundaries.emplace_back(building[0]);
			boundaries.emplace_back(building[1]);
		}
		sort(boundaries.begin(), boundaries.end());

		vector<vector<int>> result;
		int buildingsSize = buildings.size();
		int index = 0;
		for (auto& boundary : boundaries)
		{
			// ��ǰ������߽��� boundary �ص����ڴ˷����ұ߱��Լ�����߶�
			// ͬʱ���� buildingQueue �Ǵ���ѣ����������ȵõ���ߵĸ߶�
			while (index < buildingsSize && buildings[index][0] <= boundary)
			{
				buildingQueue.emplace(buildings[index][1], buildings[index][2]);
				index++;
			}
			// �ҵ������ҿ�����߸߶ȣ���ȥ���� building ����ǰ�߸��ǵ����
			while (!buildingQueue.empty() && buildingQueue.top().first <= boundary)
			{
				buildingQueue.pop();
			}

			// �߽����Ƿ�û�����κν���
			int maxHeight = buildingQueue.empty() ? 0 : buildingQueue.top().second;
			// ���߶��Ƿ������仯
			if (result.size() == 0 || maxHeight != result.back()[1]) {
				result.push_back({ boundary,maxHeight });
			}
		}

		return result;
	}
};

//int main() {
//	vector<vector<int>> buildings1{
//		{2,9,10} ,
//		{3,7,15},
//		{5,12,12},
//		{15,20,10},
//		{19,24,8}
//	};
//	vector<vector<int>> buildings2{
//		{0,2,3},
//		{2,5,3}
//	};
//	vector<vector<int>> buildings3{
//		{1,2,1},
//		{1,2,2},
//		{1,2,3},
//	};
//	vector<vector<int>> buildings4{
//		{4,9,10},
//		{4,9,15},
//		{4,9,12},
//		{10,12,10},
//		{10,12,8},
//	};
//	vector<vector<int>> buildings5{
//		{1,38,219},
//		{2,19,228},
//		{2,64,106},
//		{3,80,65},
//		{3,84,8},
//		{4,12,8},
//		{4,25,14},
//		{4,46,225},
//		{4,67,187},
//		{5,36,118},
//		{5,48,211},
//		{5,55,97},
//		{6,42,92},
//		{6,56,188},
//		{7,37,42},
//		{7,49,78},
//		{7,84,163},
//		{8,44,212},
//		{9,42,125},
//		{9,85,200},
//		{9,100,74},
//		{10,13,58},
//		{11,30,179},
//		{12,32,215},
//		{12,33,161},{12,61,198},{13,38,48},{13,65,222},{14,22,1},{15,70,222},{16,19,196},{16,24,142},{16,25,176},{16,57,114},{18,45,1},{19,79,149},{20,33,53},{21,29,41},{23,77,43},{24,41,75},{24,94,20},{27,63,2},{31,69,58},{31,88,123},{31,88,146},{33,61,27},{35,62,190},{35,81,116},{37,97,81},{38,78,99},{39,51,125},{39,98,144},{40,95,4},{45,89,229},{47,49,10},{47,99,152},{48,67,69},{48,72,1},{49,73,204},{49,77,117},{50,61,174},{50,76,147},{52,64,4},{52,89,84},{54,70,201},{57,76,47},{58,61,215},{58,98,57},{61,95,190},{66,71,34},{66,99,53},{67,74,9},{68,97,175},{70,88,131},{74,77,155},{74,99,145},{76,88,26},{82,87,40},{83,84,132},{88,99,99} };
//
//
//	Solution218GetSkyline solution;
//	solution.getSkyline(buildings1);
//	solution.getSkyline(buildings2);
//	solution.getSkyline(buildings3);
//	solution.getSkyline(buildings4);
//	solution.getSkyline(buildings5);
//}
