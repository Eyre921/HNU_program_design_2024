#include <bits/stdc++.h>
using namespace std;

// 判断字符串是否平衡
void is_balance(string s) {
	int left = 0, right = 0, point = 0;  // 初始化左侧、右侧和指针的位置
	int length = static_cast<int>(s.length());  // 获取字符串的长度

	// 找到 '^' 的位置
	for (int i = 0; i < length; i++) {
		if (s[i] == '^') {
			point = i;  // 记录 '^' 的位置
		}
	}

	// 遍历字符串，计算左侧和右侧的加权和
	for (int i = 0; i < length; i++) {
		// 如果字符是数字
		if (isdigit(s[i])) {
			int power = static_cast<int>(s[i] - '0');  // 将字符数字转换为对应的整数
			// 如果当前位置在 '^' 左边
			if (i < point)
				left += power * (point - i);  // 左侧加权和
			else  // 如果当前位置在 '^' 右边
				right += power * (i - point);  // 右侧加权和
		}
	}

	// 判断平衡状态并输出结果
	if (left == right)
		cout << "balance" << endl;  // 左右加权和相等，平衡
	else if (left > right)
		cout << "left" << endl;  // 左侧加权和大于右侧，偏左
	else
		cout << "right" << endl;  // 右侧加权和大于左侧，偏右
}

int main() {
	int n;  // 字符串数量
	cin >> n;  // 输入字符串的数量
	vector<string> s(n, "");  // 存储字符串的向量

	// 输入每个字符串并判断是否平衡
	for (int i = 0; i < n; i++) {
		cin >> s[i];  // 输入字符串
		is_balance(s[i]);  // 调用判断平衡的函数
	}
}

/*
#include <bits/stdc++.h>
using namespace std;

void is_balance(string s) {
	int left = 0, right = 0, point = 0;
	int length = static_cast<int>(s.length());
	for (int i = 0; i < length; i++) {
		if (s[i] == '^') {
			point = i;
		}
	}

	for (int i = 0; i < length; i++) {
		if (isdigit(s[i])) {
			int power = static_cast<int>(s[i] - '0');
			if (i < point)
				left += power * (point - i);
			else
				right += power * (i - point);
		}
	}

	if (left == right)
		cout << "balance" << endl;
	else if (left > right)
		cout << "left" << endl;
	else
		cout << "right" << endl;
}

int main() {
	int n;
	cin >> n;
	vector<string> s(n, "");
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		is_balance(s[i]);
	}
}

 */