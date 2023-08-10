#include "stdafx.h"

using namespace std;
class Offer05ReplaceSpace {
public:
	string replaceSpace(string& s) {
		int count = 0;
		int sLength = s.length();

		for (auto& c : s) {
			if (c == ' ') {
				count++;
			}
		}

		s.resize(count * 2 + sLength);
		for (int i = s.length() - 1, j = sLength - 1; i > j; --j) {
			if (s[j] == ' ') {
				s[i] = '0';
				s[i - 1] = '2';
				s[i - 2] = '%';
				i -= 3;
			}
			else {
				s[i] = s[j];
				i -= 1;
			}
		}

		return s;
	}
};
