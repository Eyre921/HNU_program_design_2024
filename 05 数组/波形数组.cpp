#include <iostream>
#include <vector>
using namespace std;

bool is_boxing(const vector<int> &v) {
	bool f_is_bigger = true;
	if (v[0] == v[1]) {
		return false;
	} else if (v[0] > v[1]) {
		f_is_bigger = true;
	} else if (v[0] < v[1]) {
		f_is_bigger = false;
	}

	for (size_t i = 1; i < v.size() - 1; i++) {
		if (v[i] == v[i + 1]) {
			return false;
		} else if (v[i] > v[i + 1]) {
			if (f_is_bigger)
				return false;
			else
				f_is_bigger = true;
		} else {
			if (!f_is_bigger)
				return false;
			else
				f_is_bigger = false;
		}
	}
	return true;
}

int main(void) {
	// ������
	int t;
	cin >> t;
	vector<vector<int>> v(t);
	// �������ݣ���i�飬 ��j��
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		v[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> v[i][j];
		}
	}
	// �ѵ�i�����ݴ���
	for (int i = 0; i < t; i++) {
		if (is_boxing(v[i])) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
	return 0;
}