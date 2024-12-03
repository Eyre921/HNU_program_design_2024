#include <bits/stdc++.h>
using namespace std;

// 函数 left_to_right 用来计算从两个字符串 s1 和 s2 中逐步减少字符后，最少需要删除多少次才能使两个字符串相等。
// 它通过从每个字符串中逐步去掉前面的字符并尝试找到最大公共后缀。
int left_to_right(string l, string r) {
	int l_length = static_cast<int>(l.length()); // 获取字符串 l 的长度
	int r_length = static_cast<int>(r.length()); // 获取字符串 r 的长度
	int n = l_length + r_length; // 初始的结果是两个字符串的总长度，表示删除所有字符的最坏情况

	// 遍历字符串 l，从每个位置开始截取子字符串
	for (int i = 0; i < l_length; i++) {
		// 遍历字符串 r，从每个位置开始截取子字符串
		for (int j = 0; j < r_length; j++) {
			// 如果两个子字符串从当前位置开始相等，更新 n，取较小值
			if (l.substr(i) == r.substr(j))
				n = min(n, i + j); // 更新最小的删除次数
		}
	}

	return n; // 返回最小删除次数
}

int main() {
	string s1, s2; // 定义两个输入字符串 s1 和 s2
	cin >> s1 >> s2; // 输入两个字符串

	// 输出两个方向计算的最小删除次数，取较小值
	cout << min(left_to_right(s1, s2), left_to_right(s2, s1)) << endl;
}

/*
#include <bits/stdc++.h>
using namespace std;

int left_to_right(string l, string r) {
	int l_length = static_cast<int>(l.length());
	int r_length = static_cast<int>(r.length());
	int n = l_length + r_length;
	for (int i = 0; i < l_length; i++) {
		for (int j = 0; j < r_length; j++) {
			if (l.substr(i) == r.substr(j))
				n = min(n, i + j);
		}
	}
	return n;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	cout << min(left_to_right(s1, s2), left_to_right(s2, s1)) << endl;
}

 */