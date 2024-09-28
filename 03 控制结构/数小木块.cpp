#include <iostream>
using namespace std;

int main() {
	int n, sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += (i + 1) * i / 2;
	}
	cout << sum;
	return 0;
}