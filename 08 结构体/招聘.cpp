#include <iostream>
using namespace std;

// ����ṹ�����ڴ洢ÿ��Ա��������
struct Employee {
	int skill;     // ����ֵ
	int intellect; // ����ֵ
	int loyalty;   // �ҳ϶�
	bool eliminated = false; // �Ƿ���̭��false��ʾδ��̭��true��ʾ��̭
};

int main() {
	int n;  // Ա������
	cin >> n;   // ����Ա������

	// ����һ��Ա�����飬���ڴ洢ÿ��Ա������Ϣ
	Employee employees[n];

	// ����ÿ��Ա���ļ���ֵ
	for (int i = 0; i < n; i++) {
		cin >> employees[i].skill;
	}

	// ����ÿ��Ա��������ֵ
	for (int i = 0; i < n; i++) {
		cin >> employees[i].intellect;
	}

	// ����ÿ��Ա�����ҳ϶�
	for (int i = 0; i < n; i++) {
		cin >> employees[i].loyalty;
	}

	int eliminatedCount = 0; // ����̭��Ա������

	// ����ÿ��Ա��������Ƿ���̭
	for (int i = 0; i < n; i++) {
		// �����Ա���Ѿ�����̭������
		if (employees[i].eliminated) {
			continue;
		}

		// ����Ƿ�������Ա��������ָ���϶����ڸ�Ա��
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue; // ��������Ƚ�
			}

			// ���Ա�� j �ڼ��ܡ��������ҳ϶��϶���Ա�� i ǿ����Ա�� i ����̭
			if (employees[i].skill < employees[j].skill &&
				employees[i].intellect < employees[j].intellect &&
				employees[i].loyalty < employees[j].loyalty) {

				// ���Ա�� i Ϊ����̭����������̭����
				employees[i].eliminated = true;
				eliminatedCount++;
				break;  // һ����̭�����������ڲ�ѭ��
				}
		}
	}

	// �������̭��Ա������
	cout << eliminatedCount << endl;

	return 0;
}
/*
������������

		ĳ��˾��Ҫ��Ƹһ��Ա�����ù�˾���Լ����ص�������ϵ����ӦƸ�������� 3 ��ָ�꣺����ֵ Ki���ǻ�ֵ Ii ���ҳ϶� Ei ��i=1, 2, ...

		�����ϸ�ĳ�ѡ�͸�ѡ�Լ���������Ժ��� N ���˽���������������˾������ÿ���˵ĸ���ָ��ֵ�����涨����ĳ�� i��������������� j����Ki < Kj ��Ii < Ij ��Ei < Ej ���� i ���ᱻ��̭��

		���ҳ��ܹ��ж����˻ᱻ��̭��

��������ʽ��

	   ��һ�а���һ������ N ��1�� N �� 500000������ʾ���ս��������������������ڶ��а��� N ������ Ki�������а��� N ������ Ii�������а��� N ������ Ei ��0 �� Ki��Ii �� Ei  �� 109��
�������ʽ��

	   ���Ϊһ��һ��������
���������롿

3
1 4 2
4 3 2
2 5 3
�����������

1
 */