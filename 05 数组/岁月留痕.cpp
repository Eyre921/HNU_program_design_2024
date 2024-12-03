// 数据有限版本
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool is_consecutive_days(const vector<int> &months_days) {
	// 定义一个超长的向量，包括两次非闰年和两次闰年的月份天数
	vector<int> days_in_months = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,  // 非闰年
		31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,  // 闰年
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,  // 非闰年
		31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31   // 闰年
	};

	int n = months_days.size();
	int total_length = days_in_months.size();

	// 检查输入的天数序列是否在超长向量中出现
	for (int i = 0; i <= total_length - n; ++i) {
		bool match = true;
		for (int j = 0; j < n; ++j) {
			if (months_days[j] != days_in_months[i + j]) {
				match = false;
				break;
			}
		}
		if (match)
			return true; // 找到匹配的子序列
	}

	return false; // 未找到匹配的子序列
}

int main() {
	int n;
	cin >> n;
	vector<int> months_days(n);
	for (int i = 0; i < n; ++i) {
		cin >> months_days[i];
	}

	if (is_consecutive_days(months_days)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}

	return 0;
}


// 数据很多，周全版
/*
#include <iostream>

#include <vector>
using namespace std;

// 计算这个天数可能对应的月份，包括考虑闰年与非闰年情况
#include <iostream>
#include <vector>
using namespace std;

// 计算这个天数可能对应的月份，包括考虑闰年与非闰年情况
vector<int> possible_month_cal(int m) {
    vector<int> possible_month;
    vector<int> days_in_month_normal = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> days_in_month_leap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // 遍历两个年份的月份表，检查是否匹配
    for (int i = 0; i < 12; ++i) {
        if (days_in_month_normal[i] == m) {
            possible_month.push_back(i + 1);  // 非闰年
        }
        if (days_in_month_leap[i] == m) {
            possible_month.push_back(i + 13); // 闰年，用13~24表示
        }
    }
    return possible_month;
}

bool is_ok(const vector<int> &months_days) {
    int n = static_cast<int>(months_days.size());
    vector<vector<int>> possible_months(n);

    // 计算每个数字对应可能的月份
    for (int i = 0; i < n; ++i) {
        possible_months[i] = possible_month_cal(months_days[i]);
    }

    // 遍历第一个天数可能的起点月份
    for (int start : possible_months[0]) {
        bool valid = true;
        int current_month = start;

        // 从第一个起点月份开始，逐步检查是否形成连续月份
        for (int i = 0; i < n; ++i) {
            bool found_next_month = false;
            for (int month : possible_months[i]) {
                // 检查是否满足当前连续的月份
                if (month == current_month) {
                    found_next_month = true;
                    break;
                }
            }
            if (!found_next_month) {
                valid = false;
                break;
            }
            // 更新 current_month 为下一个月份，处理跨年
            if (current_month == 12) current_month = 13; // 从普通年12月到闰年1月
            else if (current_month == 24) current_month = 1; // 从闰年12月到普通年1月
            else current_month = (current_month % 12) + 1 + (current_month > 12 ? 12 : 0);
        }

        // 找到符合条件的序列，返回true
        if (valid) {
            return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> months_days(n);
    for (int i = 0; i < n; ++i) {
        cin >> months_days[i];
    }

    if (is_ok(months_days)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

*/