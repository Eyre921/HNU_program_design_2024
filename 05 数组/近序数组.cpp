#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int find_break_one(const vector<int> &vec) {
	for (size_t i = 1; i <= vec.size() ; i++) {
		if (!(is_sorted(vec.begin(), vec.begin() + i )
				|| is_sorted(vec.begin(), vec.begin() + i, greater<int>()))) {
			return i - 1;
				}
	}
	return 0;
}

bool is_sorted_plus(const vector<int> &vec, int break_one) {
	if (is_sorted(vec.begin() + break_one, vec.end())
			|| is_sorted(vec.begin() + break_one, vec.end(), greater<int>())) {
		return true;
			}
	return false;
}

int main() {
	int n;
	cin >> n;
	if (n <= 2) {
		cout << "Yes" << endl;
		return 0;
	}
	vector<int> v(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int break_one = find_break_one(v);
	if (is_sorted_plus(v, break_one))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}
