#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int N, code;
	cin >> N;
	vector<int> weatherCounts(6, 0);

	for (int i = 0; i < N; i++) {
		cin >> code;
		if (code >= 1 && code <= 6)
			weatherCounts[code - 1]++;
	}

	const string descriptions[] = {"����", "����", "����", "С��", "����", "����"};
	for (int i = 0; i < 6; i++) {
		cout << descriptions[i] << ": " << weatherCounts[i] << endl;
	}
	return 0;
}