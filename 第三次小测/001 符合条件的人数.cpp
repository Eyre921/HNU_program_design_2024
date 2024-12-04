#include <bits/stdc++.h>  // 包含所有常用的标准库
using namespace std;  // 使用标准命名空间

int n;  // 定义一个全局变量 n，用来存储学生数量

int main()
{
    int m = 0, w = 0;  // m 用来计数符合条件的男生人数，w 用来计数符合条件的女生人数
    cin >> n;  // 输入学生人数 n
    vector<int> v1(n), v2(n);  // 定义两个大小为 n 的向量 v1 和 v2，分别存储男生和女生的身高
    for (int i = 0; i < n; i++) cin >> v1[i];  // 输入 n 个男生的身高，存储到 v1 向量中
    for (int i = 0; i < n; i++) cin >> v2[i];  // 输入 n 个女生的身高，存储到 v2 向量中

    // 遍历每个男生的身高，检查是否符合要求（身高在178到180厘米之间）
    for (int i = 0; i < n; i++)
    {
        if (178 <= v1[i] && 180 >= v1[i]) m++;  // 如果男生身高在178到180之间，男生计数 m 增加
        if (168 <= v2[i] && 170 >= v2[i]) w++;  // 如果女生身高在168到170之间，女生计数 w 增加
    }

    // 输出符合条件的男生人数和女生人数
    cout << m << " " << w << endl;
}

/*
问题描述

      　　学校组织一场活动需要选出一些同学参加礼仪队。礼仪队的身高有要求，如果是女生身高范围在168cm和170cm之间，如果是男生身高在178cm-180cm之间，分别知道n个男生和n个女生的身高请计算符合条件的男生人数和女生人数。

输入格式

第一行，输入整数n

第二行，输入n个整数，代表男生身高（厘米）

第三行，输入n个整数，代表女生身高（厘米）

输出格式

      　　输出符合条件的男生人数和女生人数

样例输入：

5

171 180 163 174 175

171 160 169 170 171



样例输出：

1 2
 */
