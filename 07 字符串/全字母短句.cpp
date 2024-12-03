#include <bits/stdc++.h>
using namespace std;

void is_full_output(const string& s) {
    // 使用 unordered_set 来存储出现的字母
    unordered_set<char> chars;

    // 遍历字符串并将字母转换为大写，添加到 chars 集合
    for (char c : s) {
        if (isalpha(c)) {
            chars.insert(toupper(c)); // 将字符转换为大写后插入集合
        }
    }

    // 检查 chars 是否包含所有字母
    if (chars.size() == 26) {
        cout << "Yes" << endl;
    } else {
        cout << "No ";
        // 输出缺失的字母
        for (char c = 'A'; c <= 'Z'; ++c) {
            if (chars.find(c) == chars.end()) {
                cout << c << " ";  // 输出缺失的字母
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();  // 忽略换行符

    // 读取并处理每个句子
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        is_full_output(s);
    }

    return 0;
}


/*
#include <bits/stdc++.h>
using namespace std;

// 判断给定的字符数组是否包含了所有的字母
bool is_full(const vector<bool> &chars) {
    // 遍历所有字母，从 'A' 到 'Z'，检查是否都存在
    for (int i = int('A'); i < int('A' + 26); i++) {
        // 如果有任何一个字母缺失，返回 false
        if (!chars[i]) {
            return false;
        }
    }
    // 所有字母都存在，返回 true
    return true;
}

// 输出给定字符串是否包含了所有字母，如果缺失则输出缺失的字母
void is_full_output(string s) {
    // 创建一个大小为 256 的布尔数组，表示每个字符的出现情况，初始化为 false
    vector<bool> chars(256, false);

    // 遍历字符串中的每个字符
    for (char &c : s) {
        // 如果是字母，则将其转为大写
        if (isalpha(c)) {
            c = toupper(c);  // 将字符转换为大写
            chars[int(c)] = true;  // 标记该字母出现过
        }
    }

    // 检查该字符串是否包含所有字母
    if (is_full(chars)) {
        cout << "Yes" << endl;  // 如果包含所有字母，输出 "Yes"
    } else {
        cout << "No" << " ";  // 否则输出 "No"，并列出缺失的字母
        // 遍历字母 'A' 到 'Z'
        for (int i = int('A'); i < int('A' + 26); i++) {
            // 如果该字母未出现，则输出该字母
            if (!chars[i]) {
                cout << char(i) << " ";  // 输出缺失的字母
            }
        }
        cout << endl;  // 换行
    }
}

int main() {
    // 读取输入中的字符串个数 n
    int n;
    cin >> n;

    // 清除输入缓冲区中的换行符，防止后续读取字符串时跳过
    cin.ignore();

    // 创建一个大小为 n 的字符串数组，用于存储输入的字符串
    vector<string> v(n, "");

    // 读取每个字符串
    for (int i = 0; i < n; i++) {
        // 读取完整的一行字符串
        getline(cin, v[i]);
    }

    // 对每个字符串进行处理，判断是否包含所有字母
    for (int i = 0; i < n; i++) {
        is_full_output(v[i]);  // 输出该字符串是否包含所有字母
    }
}
 */
/*
#include <bits/stdc++.h>
using namespace std;

bool is_full(const vector<bool> &chars) {
    for (int i = int('A'); i < int('A' + 26); i++) {
        if (!chars[i]) {
            return false;
        }
    }
    return true;
}

void is_full_output(string s) {
    vector<bool> chars(256, false);
    for (char &c : s) {
        if (isalpha(c)) {
            c = toupper(c);
            chars[int(c)] = true;
        }
    }
    if (is_full(chars)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << " ";
        for (int i = int('A'); i < int('A' + 26); i++) {
            if (!chars[i]) {
                cout << char(i) << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector<string> v(n, "");
    for (int i = 0; i < n; i++) {
        getline(cin, v[i]);
    }
    for (int i = 0; i < n; i++) {
        is_full_output(v[i]);
    }
}

 */