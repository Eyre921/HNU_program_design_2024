#include <iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	if (a < 0 || a > 100) {
		cout << "This  is  not  a  valid  number" << endl;
		return 0;
	}
	switch (a / 10) {
		case 10:
			cout  << "A" << endl;
			break;
		case 9:
			cout  << "A" << endl;
			break;
		case 8:
			cout  << "B" << endl;
			break;
		case 7:
			cout  << "C" << endl;
			break;
		case 6:
			cout  << "D" << endl;
			break;
		default:
			cout  << "E" << endl;
	}
}