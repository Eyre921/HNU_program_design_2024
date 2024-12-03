#include "judge.h"

// 质数判断函数
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

// 回文数判断函数
bool plalindrome(int a) {
	int original = a, reversed = 0;

	// 反转数字
	while (a > 0) {
		reversed = reversed * 10 + a % 10;
		a /= 10;
	}

	// 判断是否是回文数
	return original == reversed;
}