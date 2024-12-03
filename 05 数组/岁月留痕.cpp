// �������ް汾
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

bool is_consecutive_days(const vector<int> &months_days) {
	// ����һ���������������������η����������������·�����
	vector<int> days_in_months = {
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,  // ������
		31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,  // ����
		31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,  // ������
		31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31   // ����
	};

	int n = months_days.size();
	int total_length = days_in_months.size();

	// �����������������Ƿ��ڳ��������г���
	for (int i = 0; i <= total_length - n; ++i) {
		bool match = true;
		for (int j = 0; j < n; ++j) {
			if (months_days[j] != days_in_months[i + j]) {
				match = false;
				break;
			}
		}
		if (match)
			return true; // �ҵ�ƥ���������
	}

	return false; // δ�ҵ�ƥ���������
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


// ���ݺܶ࣬��ȫ��
/*
#include <iostream>

#include <vector>
using namespace std;

// ��������������ܶ�Ӧ���·ݣ�����������������������
#include <iostream>
#include <vector>
using namespace std;

// ��������������ܶ�Ӧ���·ݣ�����������������������
vector<int> possible_month_cal(int m) {
    vector<int> possible_month;
    vector<int> days_in_month_normal = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> days_in_month_leap = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // ����������ݵ��·ݱ�����Ƿ�ƥ��
    for (int i = 0; i < 12; ++i) {
        if (days_in_month_normal[i] == m) {
            possible_month.push_back(i + 1);  // ������
        }
        if (days_in_month_leap[i] == m) {
            possible_month.push_back(i + 13); // ���꣬��13~24��ʾ
        }
    }
    return possible_month;
}

bool is_ok(const vector<int> &months_days) {
    int n = static_cast<int>(months_days.size());
    vector<vector<int>> possible_months(n);

    // ����ÿ�����ֶ�Ӧ���ܵ��·�
    for (int i = 0; i < n; ++i) {
        possible_months[i] = possible_month_cal(months_days[i]);
    }

    // ������һ���������ܵ�����·�
    for (int start : possible_months[0]) {
        bool valid = true;
        int current_month = start;

        // �ӵ�һ������·ݿ�ʼ���𲽼���Ƿ��γ������·�
        for (int i = 0; i < n; ++i) {
            bool found_next_month = false;
            for (int month : possible_months[i]) {
                // ����Ƿ����㵱ǰ�������·�
                if (month == current_month) {
                    found_next_month = true;
                    break;
                }
            }
            if (!found_next_month) {
                valid = false;
                break;
            }
            // ���� current_month Ϊ��һ���·ݣ��������
            if (current_month == 12) current_month = 13; // ����ͨ��12�µ�����1��
            else if (current_month == 24) current_month = 1; // ������12�µ���ͨ��1��
            else current_month = (current_month % 12) + 1 + (current_month > 12 ? 12 : 0);
        }

        // �ҵ��������������У�����true
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