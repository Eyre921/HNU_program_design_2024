#include "judge.h"

// �����жϺ���
bool prime(int a) {
	if (a < 2)
		return false;
	for (int i = 2; i * i <= a; i++) {
		if (a % i == 0) {
			return false;
		}
	}
	return true;
}

// �������жϺ���
bool plalindrome(int a) {
	int original = a, reversed = 0;

	// ��ת����
	while (a > 0) {
		reversed = reversed * 10 + a % 10;
		a /= 10;
	}

	// �ж��Ƿ��ǻ�����
	return original == reversed;
}