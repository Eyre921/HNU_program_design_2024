#include <bits/stdc++.h>  // 引入所有常用的 C++ 标准库
using namespace std;  // 使用标准命名空间

// 函数 dp 用来计算给定字符串中最长回文子串的长度
int dp(string s)
{
    int n = s.size();  // 获取字符串的长度
    if (n == 0) return 0;  // 如果字符串为空，返回 0

    // dp[i][j] 表示字符串 s 从 i 到 j 的子串是否为回文
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1;  // 初始化最长回文子串的长度为 1，因为单个字符是回文

    // 初始化所有长度为 1 的子串（即每个字符本身）为回文
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // 从长度为 2 的子串开始检查
    for (int len = 2; len <= n; len++)
    {
        // 遍历所有可能的子串
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;  // 子串的结束位置 j
            // 判断是否是回文子串：两个端点字符相同，并且中间的子串是回文（或长度为 2）
            if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1]))
            {
                dp[i][j] = true;  // 如果是回文子串，标记为 true
                maxLen = max(maxLen, len);  // 更新最长回文子串的长度
            }
        }
    }

    return maxLen;  // 返回最长回文子串的长度
}

int main()
{
    string s;
    cin >> s;  // 输入一个字符串
    cout << dp(s) << endl;  // 输出字符串中最长回文子串的长度
    return 0;  // 程序结束
}
