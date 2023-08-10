#include "stdafx.h"

using ll = long long;
class LCP29OrchestraLayout
{
public:
	int orchestraLayout(int num, int xPos, int yPos) {
		int circle = (num + 1) / 2;
		int layer = min(min(xPos, yPos), min(num - xPos - 1, num - yPos - 1)) + 1;

		ll area = (ll)num * num;
		ll currentCircle = (ll)num - (ll)2 * (layer - 1);
		currentCircle *= currentCircle;

		ll index = (area - currentCircle) % 9 + 1;
		int right = num - layer;
		int left = layer - 1;
		// �� ��������
		if (xPos == left) {
			index += yPos - left;
		}
		// ��  | ��
		else if (yPos == right) {
			index += right - left;
			index += xPos - left;
		}
		// �� ������ ��
		else if (xPos == right) {
			index += 2 * (right - left);
			index += right - yPos;
		}
		else {
			index += 3 * (right - left);
			index += right - xPos;
		}

		return (int)(index % 9 == 0 ? 9 : index % 9);
	}
};
