#include <iostream>
#include <vector>
using namespace std;

const int MAX_LIMIT = 600000; // 定义坐标轴的最大范围

vector<int> countCoveredPoints(int n, vector<pair<int, int>> &intervals) {
	// 差分数组，用于记录区间的开始和结束
	vector<int> diff(MAX_LIMIT + 2, 0);

	// 构建差分数组
	for (const auto &interval : intervals) {
		int l = interval.first;
		int r = interval.second;
		diff[l] += 1;
		if (r + 1 <= MAX_LIMIT) {
			diff[r + 1] -= 1;
		}
	}

	// 前缀和计算覆盖次数
	vector<int> coverage(MAX_LIMIT + 1, 0);
	int current_coverage = 0;
	for (int i = 0; i <= MAX_LIMIT; ++i) {
		current_coverage += diff[i];
		coverage[i] = current_coverage;
	}

	// 统计被 k 个区间覆盖的点数
	vector<int> counts(n + 1, 0);
	for (int i = 0; i <= MAX_LIMIT; ++i) {
		if (coverage[i] >= 1 && coverage[i] <= n) {
			counts[coverage[i]] += 1;
		}
	}

	// 返回结果，从 counts[1] 到 counts[n]
	return vector<int>(counts.begin() + 1, counts.begin() + n + 1);
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> intervals(n);
	for (int i = 0; i < n; ++i) {
		cin >> intervals[i].first >> intervals[i].second;
	}

	// 调用函数并获取结果
	vector<int> result = countCoveredPoints(n, intervals);

	// 输出结果
	for (size_t i = 0; i < result.size(); ++i) {
		cout << result[i];
		if (i < result.size() - 1)
			cout << " ";
	}
	cout << endl;

	return 0;
}

// 下面是更加简单，但更耗时的实现
// 定义一个巨大的数组M，大小为limit+1，初始值为0
	// 输入组数n，定义最大最小值，用于储存所有组的中的最小起点和最大终点
	// 遍历n次
		// 输入起点和终点，并通过遍历M，将这个区间内的数组每一个值+1
		// 更新最大最小值
	// 定义数组counts[n+1]，counts[n]表示被n个数组覆盖的点数
	// 遍历数组M，最大最小值对应的区间
		// 如果 M[i] ！= 0；
			// counts[M[i]]++；
	// 输出counts[1]到couunts[n+1]的结果
/*
#include <iostream>
#include <vector>
using namespace std;

const int MAX_LIMIT = 600000; // 定义坐标轴的最大范围

vector<int> countCoveredPoints(int n, vector<pair<int, int>> &intervals) {
	// 定义一个大小为 MAX_LIMIT + 1 的数组 M，初始化为 0
	vector<int> M(MAX_LIMIT + 1, 0);

	// 遍历所有区间，直接更新 M 数组
	int min_val = MAX_LIMIT, max_val = 0; // 用于记录最小起点和最大终点
	for (const auto &interval : intervals) {
		int l = interval.first;
		int r = interval.second;
		for (int i = l; i <= r; ++i) {
			M[i] += 1;  // 将区间内的每个点加 1
		}
		// 更新最大最小值
		min_val = min(min_val, l);
		max_val = max(max_val, r);
	}

	// 统计被 k 个区间覆盖的点数
	vector<int> counts(n + 1, 0);
	for (int i = min_val; i <= max_val; ++i) {
		if (M[i] >= 1 && M[i] <= n) {
			counts[M[i]] += 1;
		}
	}

	// 返回结果，从 counts[1] 到 counts[n]
	return vector<int>(counts.begin() + 1, counts.begin() + n + 1);
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> intervals(n);

	// 输入所有区间
	for (int i = 0; i < n; ++i) {
		cin >> intervals[i].first >> intervals[i].second;
	}

	// 调用函数并获取结果
	vector<int> result = countCoveredPoints(n, intervals);

	// 输出结果
	for (size_t i = 0; i < result.size(); ++i) {
		cout << result[i];
		if (i < result.size() - 1)
			cout << " ";
	}
	cout << endl;

	return 0;
}

 */