#include <iostream>
using namespace std;

int main() {
	int Y, M, d = 0;
	cin >> Y >> M;

	if (M < 1 || M > 12)
		return 1;

	if (M == 1 || M == 3 || M == 5 || M == 7 || M == 8 || M == 10 || M == 12)
		d = 31;
	else if (M == 4 || M == 6 || M == 9 || M == 11)
		d = 30;
	else if (M == 2) {
		if ((Y % 400 == 0) || (Y % 100 != 0 && Y % 4 == 0))
			d = 29;
		else
			d = 28; // Non-leap year
	}
	cout << d << endl;
	return 0;
}
