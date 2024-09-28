#include <iomanip>
#include <iostream>
using namespace std;

int main() {
	int h1, h2, m1, m2, s1, s2;
	scanf("%i:%i:%i %i:%i:%i", &h1, &m1, &s1, &h2, &m2, &s2);
	int t1 = 3600 * h1 + 60 * m1 + s1;
	int t2 = 3600 * h2 + 60 * m2 + s2;
	int dt = t2 - t1;

	int ah = 0, am = 0, as = 0;
	if (dt > 0) {
		ah = dt / 3600;
		am = (dt % 3600) / 60;
		as = dt % 60;
	}
	cout << ah << ':'
	     << setw(2) << setfill('0') << am << ':'
	     << setw(2) << setfill('0') << as << endl;
}

