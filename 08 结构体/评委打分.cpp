#include <bits/stdc++.h>
using namespace std;

struct Contestant {
	string name;        // 选手名字
	vector<int> scores; // 评委打分
	int totalScore;     // 最终得分
};

// 比较函数：按总得分排序（降序）
bool compareByTotalScore(const Contestant &a, const Contestant &b) {
	return a.totalScore > b.totalScore; // 返回a的总分是否大于b
}

int main() {
	int n;  // 参赛选手数量
	cin >> n;
	vector<Contestant> participants(n); // 参赛者信息

	// 读取参赛者信息
	for (int i = 0; i < n; ++i) {
		cin >> participants[i].name;  // 选手名字
		participants[i].scores.resize(7);  // 每位选手7个评委的分数
		for (int j = 0; j < 7; ++j) {
			cin >> participants[i].scores[j]; // 读取每位评委的分数
		}
		// 排序并去掉最高和最低分，计算最终得分
		sort(participants[i].scores.begin(), participants[i].scores.end());
		participants[i].totalScore = accumulate(participants[i].scores.begin() + 1, participants[i].scores.end() - 1, 0);  // 计算去掉一个最高分和一个最低分后的总分
	}

	// 按照总分排序，使用传统的比较函数
	sort(participants.begin(), participants.end(), compareByTotalScore);

	// 输出排序后的结果
	for (const auto &p : participants) {
		cout << p.name << " " << p.totalScore << endl; // 输出选手姓名和得分
	}

	return 0;
}

/*
【问题描述】

	   校园卡拉OK比赛设置了7名评委，当一名选手K完歌之后，主持人报出歌手名字后，7位评委同时亮分，按照惯例，去掉一个最高分和一个最低分后，其余5位评委评分总和为该选手的最终得分。

	   一共有n组选手参加比赛，请你编写一个程序，当所有比赛结束后，列出所有选手的排名以及最终得分情况。

	   假定不会出现总分相同的情况（总分相同时，以出场顺序优先排名还是？以后再说吧！ 呵呵，暂时不管吧)。

【输入形式】

	   第1行为一个正整数n，表示参赛人数。随后n行，每行开始为选手的名字，随后7个正整数表示评委亮分情况，数据间以空格分隔。

【输出形式】

	   按名次升序输出所有选手的名字以及总分，总共n行。

【样例输入】

4
Alice 90 90 85 92 90 90 90
Bob 92 99 88 92 92 92 92
Cindy 80 85 94 94 94 94 94
Dony 95 95 100 90 95 95 95
【样例输出】

Dony 475
Cindy 461
Bob 460
Alice 450
 */