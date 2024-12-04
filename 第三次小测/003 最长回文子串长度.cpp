#include <bits/stdc++.h>  // �������г��õ� C++ ��׼��
using namespace std;  // ʹ�ñ�׼�����ռ�

// ���� dp ������������ַ�����������Ӵ��ĳ���
int dp(string s)
{
    int n = s.size();  // ��ȡ�ַ����ĳ���
    if (n == 0) return 0;  // ����ַ���Ϊ�գ����� 0

    // dp[i][j] ��ʾ�ַ��� s �� i �� j ���Ӵ��Ƿ�Ϊ����
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1;  // ��ʼ��������Ӵ��ĳ���Ϊ 1����Ϊ�����ַ��ǻ���

    // ��ʼ�����г���Ϊ 1 ���Ӵ�����ÿ���ַ�����Ϊ����
    for (int i = 0; i < n; i++) dp[i][i] = true;

    // �ӳ���Ϊ 2 ���Ӵ���ʼ���
    for (int len = 2; len <= n; len++)
    {
        // �������п��ܵ��Ӵ�
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;  // �Ӵ��Ľ���λ�� j
            // �ж��Ƿ��ǻ����Ӵ��������˵��ַ���ͬ�������м���Ӵ��ǻ��ģ��򳤶�Ϊ 2��
            if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1]))
            {
                dp[i][j] = true;  // ����ǻ����Ӵ������Ϊ true
                maxLen = max(maxLen, len);  // ����������Ӵ��ĳ���
            }
        }
    }

    return maxLen;  // ����������Ӵ��ĳ���
}

int main()
{
    string s;
    cin >> s;  // ����һ���ַ���
    cout << dp(s) << endl;  // ����ַ�����������Ӵ��ĳ���
    return 0;  // �������
}
