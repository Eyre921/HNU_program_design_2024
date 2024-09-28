#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int x;
	bool d3 = false, d7 = false, d5 = false;
	cin >> x;
	if (x % 3 == 0)
		d3 = true;
	if (x % 5 == 0)
		d5 = true;
	if (x % 7 == 0)
		d7 = true;
	if (d3 && d5 && d7)
		cout << "It's divisible by 3,5,7";
	else if (d3 && d5)
		cout << "It's divisible by 3,5";
	else if (d3 && d7)
		cout << "It's divisible by 3,7";
	else if (d5 && d7)
		cout << "It's divisible by 5,7";
	else {
		if (d3)
			cout << "It's divisible by 3";
		else if (d5)
			cout << "It's divisible by 5";
		else if (d7)
			cout << "It's divisible by 7";
		else
			cout << "null";
	}
}

