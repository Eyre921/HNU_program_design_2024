#include <iostream>
using namespace std;

double tax_compute (int income2);

int main() {
	int income, deduction;
	cin >> income >> deduction;
	int income2 = income - 5000 - deduction;
	double tax = tax_compute(income2);
	if (tax < 0)
		tax = 0;
	cout << tax;
}

double tax_compute (int income2) {
	if (income2 <= 3000)
		return income2 * 0.03;
	else if (income2 <= 12000)
		return income2 * 0.1 - 210;
	else if (income2 <= 25000)
		return income2 * 0.2 - 1410;
	else if (income2 <= 35000)
		return income2 * 0.25 - 2660;
	else if (income2 <= 55000)
		return income2 * 0.3 - 4410;
	else if (income2 <= 80000)
		return income2 * 0.35 - 7160;
	else
		return income2 * 0.45 - 15160;
}




