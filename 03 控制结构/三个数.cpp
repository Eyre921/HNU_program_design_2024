#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x[4], max = 0;
	for (int i = 0; i < 4; i++) {
		cin >> x[i];
	}
	max = x[0];
	for (int i = 1; i < 4; i++) {
		if (max < x[i])
			max = x[i];
	}

	int n = sizeof(x) / sizeof(x[0]);
	sort(x, x + n, greater<int>());

	for (int i = 1; i < 4; i++) {
		cout << max - x[i] << " ";
	}
}

