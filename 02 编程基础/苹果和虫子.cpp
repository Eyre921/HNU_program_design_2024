#include <iostream>
using namespace std;

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	int ate = (y + x - 1) / x;
	int left = n - ate;
	if (left < 0)
		left = 0;
	cout << left << endl;
	return 0;
}

