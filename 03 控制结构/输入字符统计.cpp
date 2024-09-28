#include <iostream>
#include <cctype>
using namespace std;

int main() {
	char a;
	int sum = 0, D = 0, X = 0, S = 0, Q = 0, n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (isupper(a))
			D++;
		else if (islower(a))
			X++;
		else if (isdigit(a)) {
			S++;
			sum += a - '0';
		} else
			Q++;
	}
	printf("%d %d %d %d\n", D, X, S, Q);
	if (S > 0)
		cout << sum << endl;
}

