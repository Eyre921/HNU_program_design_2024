#include <iostream>
using namespace std;

int main() {
	int t, km;
	cin >> t >> km;

	if (km < 250)
		cout << km *t;
	else if (km < 500)
		cout << t *km * 0.98;
	else if (km < 1000)
		cout << t *km * 0.95;
	else if (km < 2000)
		cout << t *km * 0.92;
	else if (km < 3000)
		cout << t *km * 0.9;
	else
		cout << t *km * 0.85;
}

