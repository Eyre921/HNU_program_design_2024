#include <iostream>
using namespace std;

int main() {
	int n = 0, qian, juli;
	char jia;
	cin >> qian >> jia >> juli;
	if (qian >= 5000)
		n++;
	if (jia == 'y')
		n++;
	if (juli <= 2000)
		n++;
	if (n >= 2)
		cout << "Accept" << endl;
	else
		cout << "Refuse" << endl;
}