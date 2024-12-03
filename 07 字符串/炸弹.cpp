#include <bits/stdc++.h>  // 引入常用的C++标准库，可以简化代码（包含了如iostream、vector等常用头文件）
using namespace std;  // 使用标准命名空间

// boomed 函数：用于计算指定位置 (x, y) 被炸掉的墙数目
int boomed(int x, int y, int n, int m, vector<string> v) {
	int boo = 0;  // 初始化计数器，用来记录当前位置 (x, y) 被炸掉的墙数目

	// 检查竖直方向 (纵向) 上是否有墙 ('*')
	for (int i = 0; i < n; i++) {
		if (v[i][y] == '*')  // 如果该位置是墙
			boo++;  // 计数器增加
	}

	// 检查水平方向 (横向) 上是否有墙 ('*')
	for (int j = 0; j < m; j++) {
		if (v[x][j] == '*' && j != y)  // 如果该位置是墙且不是当前位置
			boo++;  // 计数器增加
	}
	return boo;  // 返回炸掉的墙数
}

// can_boom 函数：用于检查是否存在某个位置，使得从该位置能炸掉所有墙
void can_boom(vector<string> v, int n, int m) {
	// 统计总墙数（' * ' 表示墙）
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '*')  // 如果该位置是墙
				total++;  // 增加总墙数
		}
	}

	// 遍历每一个位置 (i, j)，检查是否可以从该位置炸掉所有墙
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int boo = boomed(i, j, n, m, v);  // 调用 boomed 函数计算炸掉的墙数
			if (boo == total) {  // 如果从当前位置 (i, j) 能炸掉所有墙
				cout << "YES" << endl;  // 输出 YES
				return;  // 返回，表示找到了满足条件的点
			}
		}
	}

	// 如果遍历完所有位置都没有找到能够炸掉所有墙的位置，则输出 NO
	cout << "NO" << endl;
	return;  // 返回，表示无法从任何一个位置炸掉所有墙
}

// 主函数，负责处理输入和输出
int main() {
	int t;  // t 表示测试用例的数量
	cin >> t;  // 输入测试用例数量

	// 遍历每个测试用例
	for (int i = 0; i < t; i++) {
		int n, m;  // n 为行数，m 为列数
		cin >> n >> m;  // 输入行数和列数
		vector<string> v(n);  // 创建一个大小为 n 的字符串向量，用来存储每一行的墙的位置
		for (int j = 0; j < n; j++) {
			cin >> v[j];  // 输入每一行的数据（墙的位置）
		}
		can_boom(v, n, m);  // 调用 can_boom 函数检查该布局是否可以炸掉所有墙
	}

	return 0;  // 程序执行结束
}

/*
#include <bits/stdc++.h>
using namespace std;

int boomed(int x, int y, int n, int m, vector<string> v) {
	int boo = 0;
	for (int i = 0; i < n; i++) {
		if (v[i][y] == '*')
			boo++;
	}

	for (int j = 0; j < m; j++) {
		if (v[x][j] == '*' && j != y)
			boo++;
	}
	return boo;
}

void can_boom(vector<string> v, int n, int m) {
	// 统计总炸弹数和炸掉的炸弹数目
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] == '*')
				total++;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int boo = boomed(i, j, n, m, v);
			if (boo == total) {
				cout << "YES" << endl;
				return;
			}
		}
	}
	// 开始炸弹，遍历所有炸弹可能的位置，计算boomed，如果有一个是true 则整体为true
	cout << "NO" << endl;
	return;
}

int main() {
	int t;

	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		cin >> n >> m;
		vector<string> v(n);
		for (int j = 0; j < n; j++) {
			cin >> v[j];
		}
		can_boom(v, n, m);
	}
}
 */