#include <bits/stdc++.h>
using namespace std;


void isjinmore(string s) {
	int s_to_j = 0, j_to_s = 0;
	for (size_t i = 1; i < s.length(); i++) {
		if (s[i - 1] == 'S' && s[i] == 'T')
			s_to_j++;
		if (s[i - 1] == 'T' && s[i] == 'S')
			j_to_s++;
	}
	if (s_to_j > j_to_s)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main() {
	int n, t;
	cin >> n;
	vector<string> v(n, "");

	// 输入所有字符串
	for (int i = 0; i < n; i++) {
		cin >> t;
		cin >> v[i];
		isjinmore(v[i]);
	}

}
