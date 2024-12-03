#include <iostream>
using namespace std;

// 定义结构体用于存储每个员工的数据
struct Employee {
	int skill;     // 技能值
	int intellect; // 智力值
	int loyalty;   // 忠诚度
	bool eliminated = false; // 是否被淘汰，false表示未淘汰，true表示淘汰
};

int main() {
	int n;  // 员工数量
	cin >> n;   // 输入员工数量

	// 创建一个员工数组，用于存储每个员工的信息
	Employee employees[n];

	// 输入每个员工的技能值
	for (int i = 0; i < n; i++) {
		cin >> employees[i].skill;
	}

	// 输入每个员工的智力值
	for (int i = 0; i < n; i++) {
		cin >> employees[i].intellect;
	}

	// 输入每个员工的忠诚度
	for (int i = 0; i < n; i++) {
		cin >> employees[i].loyalty;
	}

	int eliminatedCount = 0; // 被淘汰的员工数量

	// 遍历每个员工，检查是否被淘汰
	for (int i = 0; i < n; i++) {
		// 如果该员工已经被淘汰，跳过
		if (employees[i].eliminated) {
			continue;
		}

		// 检查是否有其他员工在所有指标上都优于该员工
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue; // 跳过自身比较
			}

			// 如果员工 j 在技能、智力、忠诚度上都比员工 i 强，则员工 i 被淘汰
			if (employees[i].skill < employees[j].skill &&
				employees[i].intellect < employees[j].intellect &&
				employees[i].loyalty < employees[j].loyalty) {

				// 标记员工 i 为被淘汰，并增加淘汰人数
				employees[i].eliminated = true;
				eliminatedCount++;
				break;  // 一旦淘汰，立即跳出内层循环
				}
		}
	}

	// 输出被淘汰的员工数量
	cout << eliminatedCount << endl;

	return 0;
}
/*
【问题描述】

		某公司需要招聘一批员工，该公司有自己独特的评价体系，对应聘者设立了 3 个指标：技能值 Ki、智慧值 Ii 和忠诚度 Ei ，i=1, 2, ...

		经过严格的初选和复选以及各项测试以后，有 N 个人进入最后的名单，公司给出了每个人的各项指标值，并规定对于某人 i，如果存在另外人 j，有Ki < Kj 、Ii < Ij 、Ei < Ej ，则 i 将会被淘汰。

		请找出总共有多少人会被淘汰。

【输入形式】

	   第一行包含一个整数 N （1≤ N ≤ 500000），表示最终进入评价名单的人数。第二行包括 N 个整数 Ki，第三行包含 N 个整数 Ii，第四行包含 N 个整数 Ei ，0 ≤ Ki、Ii 、 Ei  ≤ 109。
【输出形式】

	   输出为一行一个整数。
【样例输入】

3
1 4 2
4 3 2
2 5 3
【样例输出】

1
 */