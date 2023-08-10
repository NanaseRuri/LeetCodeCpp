#include "stdafx.h"

class Solution420StrongPasswordChecker {
public:
    int strongPasswordChecker(string password) {
        int n = password.size();
        bool has_lower = false, has_upper = false, has_digit = false;
        for (char ch : password) {
            if (islower(ch)) {
                has_lower = true;
            }
            else if (isupper(ch)) {
                has_upper = true;
            }
            else if (isdigit(ch)) {
                has_digit = true;
            }
        }
        int categories = has_lower + has_upper + has_digit;

        if (n < 6) {
            return max(6 - n, 3 - categories);
        }
        else if (n <= 20) {
            int replace = 0;
            int cnt = 0;
            char cur = '#';

            for (char ch : password) {
                if (ch == cur) {
                    ++cnt;
                }
                else {
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            replace += cnt / 3;
            return max(replace, 3 - categories);
        }
        else {
            // �滻������ɾ������
            int replace = 0, remove = n - 20;
            // k mod 3 = 1 ����������ɾ�� 2 ���ַ����Լ��� 1 ���滻����
            int rm2 = 0;
            int cnt = 0;
            char cur = '#';

            for (char ch : password) {
                if (ch == cur) {
                    ++cnt;
                }
                else {
                    if (remove > 0 && cnt >= 3) {
                        if (cnt % 3 == 0) {
                            // ����� k % 3 = 0 ���飬��ô����ɾ�� 1 ���ַ������� 1 ���滻����
                            --remove;
                            --replace;
                        }
                        else if (cnt % 3 == 1) {
                            // ����� k % 3 = 1 ���飬��ô����������
                            ++rm2;
                        }
                        // k % 3 = 2 ����������ʽ����
                    }
                    replace += cnt / 3;
                    cnt = 1;
                    cur = ch;
                }
            }
            if (remove > 0 && cnt >= 3) {
                if (cnt % 3 == 0) {
                    --remove;
                    --replace;
                }
                else if (cnt % 3 == 1) {
                    ++rm2;
                }
            }
            replace += cnt / 3;

            // ʹ�� k % 3 = 1 �������������ʣ����滻������������ʣ���ɾ��������ͬ����
            int use2 = min({ replace, rm2, remove / 2 });
            replace -= use2;
            remove -= use2 * 2;
            // ����ÿ��һ���滻������һ���� 3 ��������ͬ���ַ���k / 3 ������������������ֱ�Ӽ����ʹ�� k % 3 = 2 ���������
            int use3 = min({ replace, remove / 3 });
            replace -= use3;
            remove -= use3 * 3;
            return (n - 20) + max(replace, 3 - categories);
        }
    }
};
