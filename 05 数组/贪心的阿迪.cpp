#include <bits/stdc++.h>
using namespace std;
// 分糖函数，输入糖的数量、人的数量、每次分配的数量、人可以收到糖的最大次数
// 返回阿迪收到的糖的数量
int fentang(int total, int n, int eachone, int max_receive)
{
    // 每轮消耗的糖数
    int everyturn = eachone * n;

    // 如果总数小于一轮
    if (total < everyturn)
    {
        // 如果总数小于一个人分的糖，那么所有糖都是阿迪的
        if (total < eachone)
        {
            return total;
        }
        return eachone;
    }

    // 可以完整分完几轮？
    int epoch = total / everyturn;

    // 如果不够分，则只会收到一组
    if (total < everyturn * epoch)
    {
        return min(eachone, total);
    }

    int left = total - everyturn * epoch;
    // 如果刚好分完，或者有剩余
    if (left >= 0)
    {
        // 如果组数满足条件
        if (epoch < max_receive)
        {
            return eachone * epoch + min(left, eachone);
        }
        return eachone * min(epoch, max_receive);
    }
    return 0;
}

int main()
{
    // 分糖函数，输入糖的数量、人的数量、一次最多分到的糖数、人可以收到糖的最大次数
    int total, n, max_fen, max_ci, a_result = 0;
    cin >> total >> n >> max_fen >> max_ci;

    for (int i = max_fen; i > 0; i--)
    {
        int tang = fentang(total, n, i, max_ci);
        if (tang > a_result)
            a_result = tang;
    }
    cout << a_result << endl;
}
