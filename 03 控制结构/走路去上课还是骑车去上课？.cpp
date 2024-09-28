#include <iostream>
using namespace std;

int main() {
	int distance;
	cin >> distance;
	double b_time, w_time;

	b_time = 50 + distance / 3.0;
	w_time = distance / 1.2;

	if (b_time > w_time)
		cout << "Walk";
	else if (b_time < w_time)
		cout << "Bike";
	else
		cout << "All";
}
