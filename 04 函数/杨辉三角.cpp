#include <iostream>
#include "yang.h"
using namespace std;

// ��ӡǰ���ո�
void PrintBlank(int num) {
	for (int i = 0; i < num; i++) {
		cout << " ";
	}
}

// ���㲢��ӡ������ǵ� row �е�ϵ��
void PrintCombine(int row) {
	int coef = 1; // ��ʼ����һ��ϵ��
	for (int i = 0; i < row; i++) {
		cout << coef << " "; // ��ӡϵ�����������
		coef = coef * (row - i - 1) / (i + 1); // ������һ��ϵ��
	}
}
