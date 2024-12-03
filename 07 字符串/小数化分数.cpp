#include <bits/stdc++.h>
using namespace std;

// 使用欧几里得算法计算最大公约数
long long gcd(long long a, long long b) {
	while (b != 0) {
		a %= b;
		swap(a, b);  // 使用 std::swap 来交换
	}
	return a;
}

// 处理有限小数
void youxian(string s) {
	// 截取小数部分
	string s1 = s.substr(2);  // 从小数点后开始
	long long a = stoll(s1);  // 转换为 long long
	long long b = 1;

	// 计算 10 的幂
	for (size_t i = 0; i < s1.length(); ++i)
		b *= 10;

	// 计算最大公约数并简化分数
	long long gcd_ab = gcd(a, b);
	a /= gcd_ab;
	b /= gcd_ab;

	cout << a << '/' << b << endl;
}

// 处理无限小数
void wuxian(string s) {
	string s0 = s.substr(2);  // 去掉"0."

	// 找到括号的位置
	int left = s0.find('(');
	int right = s0.find(')');

	// 提取有限部分和循环部分
	string lim = s0.substr(0, left);  // 有限部分
	string inf = s0.substr(left + 1, right - left - 1);  // 循环部分

	long long a1 = 0, b1 = 1, a2 = 0, b2 = 1;

	// 处理有限部分（如果存在）
	if (!lim.empty()) {
		a1 = stoll(lim);  // 将有限部分转换为长整型
		b1 = 1;
		for (size_t i = 0; i < lim.length(); ++i)
			b1 *= 10;  // 计算有限部分的分母
	}

	// 处理循环部分（如果存在）
	if (!inf.empty()) {
		a2 = stoll(inf);  // 将循环部分转换为长整型
		b2 = 1;
		for (size_t i = 0; i < inf.length(); ++i)
			b2 *= 10;  // 计算循环部分的分母
		b2 -= 1;  // 循环小数部分减去 1
	}

	// 将 b2 扩展以适应有限部分
	for (size_t i = 0; i < lim.length(); ++i)
		b2 *= 10;

	long long a = a1 * b2 + a2 * b1;  // 完整的分子
	long long b = b1 * b2;  // 完整的分母

	// 计算最大公约数并简化分数
	long long gcd_ab = gcd(a, b);
	a /= gcd_ab;
	b /= gcd_ab;

	cout << a << '/' << b << endl;  // 输出最简分数
}



int main() {
	int t;
	cin >> t;  // 输入测试用例数量
	vector<string> v(t);

	for (int i = 0; i < t; i++) {
		cin >> v[i];  // 输入每个小数表示的字符串

		// 判断是否为无限小数
		if (v[i].find("(") != string::npos) {
			wuxian(v[i]);
		} else {
			youxian(v[i]);
		}
	}
	return 0;
}
