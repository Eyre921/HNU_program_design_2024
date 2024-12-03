#include <bits/stdc++.h>
using namespace std;

// 计算n的所有因子并存入factors向量
void cal_factor(int n, vector<int> &factors) {
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {  // 如果i是n的因子
			factors.push_back(i);  // 将因子i加入factors
		}
	}
}

int main() {
	string s;
	getline(cin, s);  // 读取整行输入字符串
	vector<int> factors;  // 用于存储因子
	int n = static_cast<int>(s.length());  // 获取字符串的长度

	cal_factor(n, factors);  // 计算字符串长度n的所有因子并存入factors

	// 根据每个因子的位置，反转字符串的前factors[i]个字符
	for (size_t i = 0; i < factors.size(); i++) {
		reverse(s.begin(), s.begin() + factors[i]);  // 反转从字符串开头到factors[i]位置的子字符串
	}

	cout << s;  // 输出处理后的字符串
}

/*
#include <bits/stdc++.h>
using namespace std;

void cal_factor (int n, vector<int> &factors) {
	for (int i = 1; i <= n; i++) {
		if (n % i == 0) {
			factors.push_back(i);
		}
	}
}

int main() {
	string s;
	getline(cin, s);
	vector<int> factors;
	int n = static_cast<int>(s.length());
	cal_factor(n, factors);
	for (size_t i = 0; i < factors.size(); i++) {
		reverse(s.begin(), s.begin() + factors[i] );
	}
	cout << s;
}

 */