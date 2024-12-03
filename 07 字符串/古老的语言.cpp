#include <bits/stdc++.h>
using namespace std;

// 判断字符是否为辅音字母（不包括元音 'a', 'e', 'i', 'o', 'u'）
bool is_fu(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return false;  // 元音字母返回 false
	else
		return true;   // 其他字母视为辅音字母，返回 true
}

int main() {
	string s;
	cin >> s;  // 输入字符串 s

	// 判断字符串的最后一个字符是否为辅音字母且不是 'n'
	if (is_fu(s.back()) && s.back() != 'n') {
		cout << "NO" << endl;  // 如果最后一个字符是辅音且不是 'n'，输出 "NO"
		return 0;  // 提前退出
	}

	// 遍历字符串中的每一对相邻字符，检查是否符合条件
	for (size_t i = 0; i < s.length() - 1; i++) {
		// 如果当前字符和下一个字符都是辅音字母，且当前字符不是 'n'
		if (is_fu(s[i]) && is_fu(s[i + 1]) && s[i] != 'n') {
			cout << "NO" << endl;  // 如果遇到连续的两个辅音字母且第一个字符不是 'n'，输出 "NO"
			return 0;  // 提前退出
		}
	}

	cout << "YES" << endl;  // 如果没有违反规则的情况，输出 "YES"
}
/*
#include <bits/stdc++.h>
using namespace std;

bool is_fu(char c) {
	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
		return false;
	else
		return true;
}

int main() {
	string s;
	cin >> s;
	if (is_fu(s.back()) && s.back() != 'n') {
		cout << "NO" << endl;
		return 0;
	}
	for (size_t i = 0; i < s.length() - 1; i++) {
		if (is_fu(s[i]) && is_fu(s[i + 1]) && s[i] != 'n') {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}

 */