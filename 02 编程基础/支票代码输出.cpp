#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int checkCode;
	double amount;

	// ����֧Ʊ����ͽ��
	cin >> checkCode >> amount;

	// ���֧Ʊ���룬ȷ��8λ��ǰ�油��0��
	cout << setw(8) << setfill('0') << checkCode << endl;

	// �����������λС��
	cout << fixed << setprecision(2) << amount << endl;

	return 0;
}

