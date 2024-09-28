#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int checkCode;
	double amount;

	// 输入支票代码和金额
	cin >> checkCode >> amount;

	// 输出支票代码，确保8位，前面补‘0’
	cout << setw(8) << setfill('0') << checkCode << endl;

	// 输出金额，保留两位小数
	cout << fixed << setprecision(2) << amount << endl;

	return 0;
}

