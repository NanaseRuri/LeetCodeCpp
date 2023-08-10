#include "stdafx.h"

using namespace std;

class Solution135Candy
{
public:
	int candy(vector<int>& ratings) {
		int ratingsSize = ratings.size();
		vector<int> candiesLeftToRight(ratingsSize);
		vector<int> candiesRightToLeft(ratingsSize);

		candiesLeftToRight[0] = 1;
		candiesRightToLeft[ratingsSize - 1] = 1;

		int candies = 1;
		for (int i = 1; i < ratingsSize; i++)
		{
			if (ratings[i] > ratings[i - 1]) {
				candies++;
			}
			else {
				candies = 1;
			}
			candiesLeftToRight[i] = candies;
		}
		candies = 1;
		for (int i = ratingsSize - 2; i >= 0; i--)
		{
			if (ratings[i] > ratings[i + 1]) {
				candies++;
			}
			else {
				candies = 1;
			}
			candiesRightToLeft[i] = candies;
		}

		int result = 0;
		for (int i = 0; i < ratingsSize; i++)
		{
			result += max(candiesLeftToRight[i], candiesRightToLeft[i]);
		}

		return result;
	}

	int candy1(vector<int>& ratings) {
		int ratingsSize = ratings.size();
		int result = 1;
		int increase = 1;
		int decrease = 0;
		int candies = 1;

		for (int i = 1; i < ratingsSize; i++)
		{
			if (ratings[i] >= ratings[i - 1]) {
				decrease = 0;
				candies = ratings[i] == ratings[i - 1] ? 1 : candies + 1;
				result += candies;
				increase = candies;
			}
			else {
				decrease++;
				// ��Ϊ���ҵ�����������ȴ����ҵ����ĸ���ʱ����Ҫ���� +1
				if (decrease == increase) {
					decrease++;
				}
				result += decrease;
				candies = 1;
			}
		}
	}
};
