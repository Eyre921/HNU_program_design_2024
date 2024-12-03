#include <bits/stdc++.h>
using namespace std;

// 判断字符串是否安全
void is_safe(string s) {
	int n = static_cast<int>(s.length());  // 获取字符串的长度
	vector<int> arr(n, 0);  // 初始化一个数组arr，用于记录每个位置是否被覆盖

	// 遍历字符串的每个字符
	for (int i = 0; i < n; i++) {
		// 如果当前字符是数字
		if (isdigit(s[i])) {
			int num = static_cast<int>(s[i] - '0');  // 获取数字的值
			arr[i]++;  // 当前字符所在位置被标记

			// 向左和向右扩展标记
			for (int j = 1; j <= num; j++) {
				// 如果左边位置在范围内，则标记该位置
				if (i + j < n && i + j >= 0) {
					arr[i + j]++;
				}
				// 如果右边位置在范围内，则标记该位置
				if (i - j < n && i - j >= 0) {
					arr[i - j]++;
				}
			}
		}
	}

	// 检查是否有位置被标记超过一次
	for (int i = 0; i < n; i++) {
		// 如果某个位置被标记超过一次，则说明不安全
		if (arr[i] > 1) {
			cout << "unsafe" << endl;
			return;
		}
	}

	// 如果所有位置都没有被标记超过一次，则说明安全
	cout << "safe" << endl;
}

int main() {
	int t;
	cin >> t;  // 输入测试用例的数量
	vector<string> s(t);  // 存储每个测试用例的字符串

	// 输入每个测试用例的字符串
	for (int i = 0; i < t; i++) {
		cin >> s[i];
		is_safe(s[i]);  // 检查当前字符串是否安全
	}
}
/*
#include <bits/stdc++.h>
using namespace std;

void is_safe(string s) {
	int n = static_cast<int>(s.length());
	vector<int> arr(n, 0);

	for (int i = 0; i < n; i++) {
		if (isdigit(s[i])) {
			int num = static_cast<int>(s[i] - '0');
			arr[i]++;
			for (int j = 1; j <= num; j++) {
				if (i + j < n && i + j >= 0) {
					arr[i + j]++;
				}
				if (i - j < n && i - j >= 0) {
					arr[i - j]++;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (arr[i] > 1) {
			cout << "unsafe" << endl;
			return;
		}
	}

	cout << "safe" << endl;
}

int main() {
	int t;
	cin >> t;
	vector<string> s(t);
	for (int i = 0; i < t; i++) {
		cin >> s[i];
		is_safe(s[i]);
	}
}

 */

/*
#include <bits/stdc++.h>
using namespace std;

void is_safe(string s) {
	int n = static_cast<int>(s.length());
	vector<int> visited(n, 0);  // 用来记录每个位置是否有机器人到达

	for (int i = 0; i < n; i++) {
		if (isdigit(s[i])) {
			int power = s[i] - '0';  // 机器人可以移动的最大步数
			// 对于机器人s[i]，其活动范围是[i - power, i + power]
			int left = max(0, i - power);  // 左边界，不能小于0
			int right = min(n - 1, i + power);  // 右边界，不能超过n-1

			// 更新该范围内的所有位置
			for (int j = left; j <= right; j++) {
				visited[j]++;
				if (visited[j] > 1) {  // 如果某位置被多个机器人到达，发生碰撞
					cout << "unsafe" << endl;
					return;
				}
			}
		}
	}
	cout << "safe" << endl;  // 如果没有发生碰撞，输出safe
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		is_safe(s);  // 检查每个字符串是否安全
	}
	return 0;
}

 */