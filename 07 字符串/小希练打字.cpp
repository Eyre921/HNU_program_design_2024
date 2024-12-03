#include <bits/stdc++.h>
using namespace std;

// 计算某个字符串的输入时间
double time_cal(const vector<string> &v, vector<int> &v_time, int index) {
    // 检查之前是否已经输入过相同的字符串，避免重复计算
    for (int i = 0; i < index; i++) {
        if (v[i] == v[index]) {
            // 如果输入过，直接返回之前计算的时间的一半
            return v_time[i] / 2;
        }
    }

    string left_cha = "qwertasdfgzxcvbQWERTASDFGZXCVB"; // 左手字符集
    int t = 0; // 用于存储当前字符串的输入时间

    // 遍历当前字符串的每个字符
    for (size_t i = 0; i < v[index].size(); i++) {
        if (i == 0) {
            t += 2; // 第一个字母总是加2
        } else {
            // 不是第一个字母，判断当前字母和前一个字母的手部是否一致
            if (left_cha.find(v[index][i]) != string::npos) { // 当前字母是左手输入
                if (left_cha.find(v[index][i - 1]) != string::npos) { // 前一个字母是左手
                    t += 4; // 左手->左手
                } else {
                    t += 2; // 右手->左手
                }
            } else { // 当前字母是右手输入
                if (left_cha.find(v[index][i - 1]) != string::npos) { // 前一个字母是左手
                    t += 2; // 左手->右手
                } else {
                    t += 4; // 右手->右手
                }
            }
        }
    }

    return t;
}

int main() {
    int n; // 字符串的个数
    int s_time = 0; // 总时间
    cin >> n; // 输入字符串个数
    vector<string> v(n, ""); // 存储所有字符串
    vector<int> v_time(n, 0); // 存储每个字符串的计算时间

    // 输入所有字符串
    for (int i = 0; i < n; i++) {
        cin >> v[i]; // 输入字符串
    }

    // 处理每个输入的字符串，计算其时间并累加
    for (int i = 0; i < n; i++) {
        v_time[i] = time_cal(v, v_time, i); // 计算当前字符串的时间
        s_time += v_time[i]; // 将当前字符串的时间累加到总时间
    }

    cout << s_time << endl; // 输出总时间
}

/*
#include <bits/stdc++.h>
using namespace std;

double time_cal(const vector<string> &v, vector<int> &v_time, int index) {
    for (int i = 0; i < index; i++) {
        if (v[i] == v[index]) {
            return v_time[i] / 2;
        }
    }

    string left_cha = "qwertasdfgzxcvbQWERTASDFGZXCVB";
    int t = 0;

    for (size_t i = 0; i < v[index].size(); i++) {
        if (i == 0) {
            t += 2;
        } else {
            if (left_cha.find(v[index][i]) != string::npos) {
                if (left_cha.find(v[index][i - 1]) != string::npos) {
                    t += 4;
                } else {
                    t += 2;
                }
            } else {
                if (left_cha.find(v[index][i - 1]) != string::npos) {
                    t += 2;
                } else {
                    t += 4;
                }
            }
        }
    }

    return t;
}

int main() {
    int n;
    int s_time = 0;
    cin >> n;
    vector<string> v(n, "");
    vector<int> v_time(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    for (int i = 0; i < n; i++) {
        v_time[i] = time_cal(v, v_time, i);
        s_time += v_time[i];
    }

    cout << s_time << endl;
}

 */