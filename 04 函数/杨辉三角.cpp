#include <iostream>
#include "yang.h"
using namespace std;

// 打印前导空格
void PrintBlank(int num) {
	for (int i = 0; i < num; i++) {
		cout << " ";
	}
}

// 计算并打印杨辉三角第 row 行的系数
void PrintCombine(int row) {
	int coef = 1; // 初始化第一个系数
	for (int i = 0; i < row; i++) {
		cout << coef << " "; // 打印系数，调整宽度
		coef = coef * (row - i - 1) / (i + 1); // 计算下一个系数
	}
}
