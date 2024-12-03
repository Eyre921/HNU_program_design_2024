#include <iostream>
#include <vector>
using namespace std;

const int MAX_LIMIT = 600000; // ��������������Χ

vector<int> countCoveredPoints(int n, vector<pair<int, int>> &intervals) {
	// ������飬���ڼ�¼����Ŀ�ʼ�ͽ���
	vector<int> diff(MAX_LIMIT + 2, 0);

	// �����������
	for (const auto &interval : intervals) {
		int l = interval.first;
		int r = interval.second;
		diff[l] += 1;
		if (r + 1 <= MAX_LIMIT) {
			diff[r + 1] -= 1;
		}
	}

	// ǰ׺�ͼ��㸲�Ǵ���
	vector<int> coverage(MAX_LIMIT + 1, 0);
	int current_coverage = 0;
	for (int i = 0; i <= MAX_LIMIT; ++i) {
		current_coverage += diff[i];
		coverage[i] = current_coverage;
	}

	// ͳ�Ʊ� k �����串�ǵĵ���
	vector<int> counts(n + 1, 0);
	for (int i = 0; i <= MAX_LIMIT; ++i) {
		if (coverage[i] >= 1 && coverage[i] <= n) {
			counts[coverage[i]] += 1;
		}
	}

	// ���ؽ������ counts[1] �� counts[n]
	return vector<int>(counts.begin() + 1, counts.begin() + n + 1);
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> intervals(n);
	for (int i = 0; i < n; ++i) {
		cin >> intervals[i].first >> intervals[i].second;
	}

	// ���ú�������ȡ���
	vector<int> result = countCoveredPoints(n, intervals);

	// ������
	for (size_t i = 0; i < result.size(); ++i) {
		cout << result[i];
		if (i < result.size() - 1)
			cout << " ";
	}
	cout << endl;

	return 0;
}

// �����Ǹ��Ӽ򵥣�������ʱ��ʵ��
// ����һ���޴������M����СΪlimit+1����ʼֵΪ0
	// ��������n�����������Сֵ�����ڴ�����������е���С��������յ�
	// ����n��
		// ���������յ㣬��ͨ������M������������ڵ�����ÿһ��ֵ+1
		// ���������Сֵ
	// ��������counts[n+1]��counts[n]��ʾ��n�����鸲�ǵĵ���
	// ��������M�������Сֵ��Ӧ������
		// ��� M[i] ��= 0��
			// counts[M[i]]++��
	// ���counts[1]��couunts[n+1]�Ľ��
/*
#include <iostream>
#include <vector>
using namespace std;

const int MAX_LIMIT = 600000; // ��������������Χ

vector<int> countCoveredPoints(int n, vector<pair<int, int>> &intervals) {
	// ����һ����СΪ MAX_LIMIT + 1 ������ M����ʼ��Ϊ 0
	vector<int> M(MAX_LIMIT + 1, 0);

	// �����������䣬ֱ�Ӹ��� M ����
	int min_val = MAX_LIMIT, max_val = 0; // ���ڼ�¼��С��������յ�
	for (const auto &interval : intervals) {
		int l = interval.first;
		int r = interval.second;
		for (int i = l; i <= r; ++i) {
			M[i] += 1;  // �������ڵ�ÿ����� 1
		}
		// ���������Сֵ
		min_val = min(min_val, l);
		max_val = max(max_val, r);
	}

	// ͳ�Ʊ� k �����串�ǵĵ���
	vector<int> counts(n + 1, 0);
	for (int i = min_val; i <= max_val; ++i) {
		if (M[i] >= 1 && M[i] <= n) {
			counts[M[i]] += 1;
		}
	}

	// ���ؽ������ counts[1] �� counts[n]
	return vector<int>(counts.begin() + 1, counts.begin() + n + 1);
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> intervals(n);

	// ������������
	for (int i = 0; i < n; ++i) {
		cin >> intervals[i].first >> intervals[i].second;
	}

	// ���ú�������ȡ���
	vector<int> result = countCoveredPoints(n, intervals);

	// ������
	for (size_t i = 0; i < result.size(); ++i) {
		cout << result[i];
		if (i < result.size() - 1)
			cout << " ";
	}
	cout << endl;

	return 0;
}

 */