   #include <bits/stdc++.h>
using namespace std;

// 检查邮箱地址是否有效
int check_valid_email(string &email) {
    int username_valid_letter_count = 0, domain_valid = 0, domain_letter_count = 0;
    string username;

    // 查找 "." 和 "@" 在邮箱中的位置
    size_t dot_pos = email.find(".");
    size_t at_pos = email.find("@");

    // 如果 "." 出现在 "@" 前，提取 "@" 前的部分作为用户名
    if (dot_pos != string::npos && dot_pos < at_pos)
        username = email.substr(dot_pos + 1, at_pos - dot_pos - 1); // 获取 "@" 与 "." 之间的部分
    // 如果 "." 在 "@" 后，提取 "@" 之前的部分作为完整的用户名
    else if (at_pos != string::npos && dot_pos > at_pos)
        username = email.substr(0, at_pos + 1);
    else
        username = ""; // 无效的邮箱格式

    // 删除用户名和 "@" 后的部分，保留域名部分
    email.erase(0, at_pos + 1);

    // 查找域名中的 "." 和 "_" 位置
    size_t dot_pos_in_domain = email.find(".");
    size_t underscore_pos_in_domain = email.find("_");

    // 判断域名是否合法：确保 "." 前没有 "_"，且 "." 存在
    if (dot_pos_in_domain != string::npos &&
        (underscore_pos_in_domain == string::npos || underscore_pos_in_domain > dot_pos_in_domain))
        domain_valid = 1;  // 合法域名
    else
        domain_valid = 0;  // 不合法域名

    // 删除域名中的 "." 和之前的部分
    email.erase(0, dot_pos_in_domain + 1);

    // 统计用户名部分的有效字母数量
    if (username.length() != 0) {
        for (size_t i = 0; i < username.length(); i++) {
            if (username[i] >= 'a' && username[i] <= 'z')
                username_valid_letter_count++;  // 统计小写字母
        }
    }

    // 统计域名部分的有效字母数量（从"."后开始）
    for (size_t i = 0; i < email.length(); i++) {
        if (email[i] < 'a' || email[i] > 'z') {
            break;  // 遇到非法字符停止统计
        }
        domain_letter_count++;  // 统计字母数量
    }

    // 返回邮箱是否合法的判断结果（合法条件为：用户名字母数 * 域名合法性 * 域名字母数）
    return username_valid_letter_count * domain_valid * domain_letter_count;
}

int main() {
    string email;
    int total_valid_emails = 0, is_valid = 1;

    cin >> email;  // 输入邮箱地址

    // 循环检查每个子邮箱地址是否合法，并累加有效的邮箱数量
    while (is_valid) {
        is_valid = check_valid_email(email);
        total_valid_emails += is_valid;
    }

    // 输出有效邮箱的总数量
    cout << total_valid_emails << endl;
    return 0;
}
