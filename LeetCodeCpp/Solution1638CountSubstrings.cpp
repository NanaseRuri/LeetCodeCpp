#include "stdafx.h"

using namespace std;

class Solution1638CountSubstrings
{
public:
	int countSubstrings(string s, string t) {
		int sLength = s.length();
		int tLength = t.length();

		int result = 0;
		for (int i = 0; i < sLength; i++) {
			for (int j = 0; j < tLength; j++) {
				int diff = 0;
				for (int k = 0; k < sLength - i && k < tLength - j; k++) {
					diff += s[i + k] == t[j + k] ? 0 : 1;
					if (diff > 1) {
						break;
					}
					else if (diff == 1) {
						result++;
					}
				}
			}
		}

		return result;
	}

	int countSubstrings1(string s, string t) {
		int sLength = s.length();
		int tLength = t.length();

		int result = 0;
		for (int i = 0; i < sLength; i++) {
			for (int j = 0; j < tLength; j++) {
				if (s[i] != t[j]) {
					int leftCount = 0;
					int rightCount = 0;

					int sLeft = i - 1;
					int tLeft = j - 1;
					while (sLeft >= 0 && tLeft >= 0 && s[sLeft] == t[tLeft]) {
						sLeft--;
						tLeft--;
						leftCount++;
					}

					int sRight = i + 1;
					int tRight = j + 1;

					while (sRight < sLength && tRight < tLength && s[sRight] == t[tRight]) {
						sRight++;
						tRight++;
						rightCount++;
					}

					result += (leftCount + 1) * (rightCount + 1);
				}
			}
		}

		return result;
	}

	int countSubstrings2(string s, string t) {
		int sLength = s.length();
		int tLength = t.length();

		vector<vector<int>> dpLeft(sLength + 1, vector<int>(tLength + 1));
		vector<vector<int>> dpRight(sLength + 1, vector<int>(tLength + 1));

		for (int i = 0; i < sLength; i++) {
			for (int j = 0; j < tLength; j++) {
				if (s[i] == t[j]) {
					dpLeft[i + 1][j + 1] = dpLeft[i][j] + 1;
				}
			}
		}

		for (int i = sLength - 1; i >= 0; i--) {
			for (int j = tLength - 1; j >= 0; j--) {
				if (s[i] == t[j]) {
					dpRight[i][j] = dpRight[i + 1][j + 1] + 1;
				}
			}
		}

		int result = 0;
		for (int i = 0; i < sLength; i++) {
			for (int j = 0; j < tLength; j++) {
				if (s[i] != t[j]) {
					result += (dpLeft[i][j] + 1) * (dpRight[i + 1][j + 1] + 1);
				}
			}
		}

		return result;
	}

	// ��¼�ϴ������ϴγ��ֵĲ�ͬ���±꣬�����������ǰ�����������������ַ��������������� dp ʱ������
	int countSubstrings3(string s, string t) {
		int sLength = s.length();
		int tLength = t.length();

		int result = 0;

		// �ַ��� s ���ַ��� t ��ѡ�е��±�֮��
		// i �� [0, sLength) , j �� [0, tLength)���� d �� [1 - tLength, sLength)
		for (int d = 1 - tLength; d < sLength; d++) {
			int i = max(d, 0);

			for (int k0 = i - 1, k1 = k0; i < sLength && i - d < tLength; i++) {
				if (s[i] != t[i - d]) {
					k0 = k1;
					k1 = i;
				}

				result += k1 - k0;
			}
		}

		return result;
	}
};

//int main() {
//	Solution1638CountSubstrings solution;
//	string s = "aba";
//	string t = "baba";
//	string s1 = "abe";
//	string t1 = "bbc";
//	solution.countSubstrings(s, t);
//	solution.countSubstrings1(s1, t1);
//	solution.countSubstrings2(s, t);
//	solution.countSubstrings2(s1, t1);
//	solution.countSubstrings3(s, t);
//	solution.countSubstrings3(s1, t1);
//}
