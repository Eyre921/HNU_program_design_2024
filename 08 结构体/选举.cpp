#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;  // n：候选人数量，m：城市数量
	cin >> n >> m;

	// 使用数组存储每个候选人的获胜次数
	vector<int> wins(n, 0);  // wins[i] 表示候选人 i 获胜的城市数
	vector<int> votes(n);    // 存储每轮投票结果

	// 处理每一轮的投票数据
	for (int city = 0; city < m; city++) {
		int maxVotes = 0;  // 当前城市的最大得票数

		// 读取当前城市所有候选人的得票数，并找出最大票数
		for (int i = 0; i < n; i++) {
			cin >> votes[i];  // 存储候选人 i 的得票数
			maxVotes = max(maxVotes, votes[i]);  // 更新最大得票数
		}

		// 找到得票最多的候选人，为其加一胜
		for (int i = 0; i < n; i++) {
			if (votes[i] == maxVotes) {
				wins[i]++;  // 增加该候选人赢得的城市数
				break;  // 每轮只给一个获胜者
			}
		}
	}

	// 找到赢得最多城市的候选人
	int maxWins = 0;
	for (int i = 0; i < n; i++) {
		maxWins = max(maxWins, wins[i]);  // 找到最大获胜城市数
	}

	// 找到获胜次数最多的候选人并输出
	for (int i = 0; i < n; i++) {
		if (wins[i] == maxWins) {
			cout << i + 1;  // 输出获胜者的编号 (从 1 开始)
			break;  // 找到后立即输出并结束
		}
	}

	return 0;
}
/*
【问题描述】

	   在一场全国性选举中，有n位候选人，编号从1~n，这个国家有m个城市，已知每个城市每个候选人的得票数。

	   这个国家的选举制度很不寻常。在选举的第一阶段，每个城市的票数被计算出来，在每个城市，获胜者为得票最多的候选人，如果有相同得票数，则编号最小的获胜。

	   在第二个阶段，比较赢得的城市数，赢得的城市最多者获胜，如果赢得的城市数相等，则编号小者获胜。

	   请确定最终谁将获得选举胜利。

【输入形式】

	   输入的第一行为两个正整数n和m (1≤n,m≤100)，表示候选人的个数和城市的个数。

	   接下来的m行，每行包含n个非负整数，第i行的第j个数aij(1≤j≤n, 1≤i≤m, 0≤aij≤109) 表示第j个候选人在第i个城市的得票数。

【输出形式】

	   输出为一个数，最终获胜者的编号。
【样例输入】

3 3
1 2 3
2 3 1
1 2 1
【样例输出】

2
 */