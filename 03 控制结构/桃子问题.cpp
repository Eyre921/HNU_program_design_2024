#include <iostream>
using namespace std;

int main() {
	int n, s = 1;
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		s = (s + 1) * 2;
	}
	cout << s;
}

