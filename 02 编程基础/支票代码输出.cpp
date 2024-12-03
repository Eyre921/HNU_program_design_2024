#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int checkCode;
	double amount;

	cin >> checkCode >> amount;

	cout << setw(8) << setfill('0') << checkCode << endl;

	cout << fixed << setprecision(2) << amount << endl;

	return 0;
}

