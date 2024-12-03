#include <bits/stdc++.h>
using namespace std;

void rm_wub(string &s) {
	size_t pos = 0;
    // 直到没有wub
	while ((pos = s.find("WUB", pos)) != string::npos) {
		s.erase(pos, 3);  // 删除找到的 "WUB"
		// 如果 pos 不是字符串的开头，并且前一个字符不是空格，就插入一个空格
		if (pos != 0 && s[pos - 1] != ' ')
			s.insert(pos, " ");
	}
}

int main() {
	string s;
	cin >> s;
	rm_wub(s);
	cout << s;
}