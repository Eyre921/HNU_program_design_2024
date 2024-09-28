#include <iostream>
using namespace std;

int main() {
	int cr = 1, cy = 2, cg = 3, cc = 4, cb = 5, cp = 6, cB = 7, n = 0, sum = 0, rnum = 0, rin = 0;
	cin >> n;
	char balltmp = '0';
	for (int i = 0; i < n; i++) {
		cin >> balltmp;
		if (balltmp == 'r') {
			cin >> rin;
			rnum += rin;
			if (rnum <= 15)
				sum += rin;
		} else if (balltmp == 'y')
			sum += cy;
		else if (balltmp == 'g')
			sum += cg;
		else if (balltmp == 'c')
			sum += cc;
		else if (balltmp == 'b')
			sum += cb;
		else if (balltmp == 'p')
			sum += cp;
		else if (balltmp == 'B')
			sum += cB;
	}
	cout << sum << endl;
}

