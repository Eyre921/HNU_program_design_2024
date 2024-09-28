#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	float f, c;
	cin >> f;
	c = 5 * (f - 32) / 9;
	cout << fixed << setprecision(5) << c << endl;
	return 0;
}

