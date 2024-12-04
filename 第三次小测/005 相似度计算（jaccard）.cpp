#include <bits/stdc++.h>  // 引入所有常用的 C++ 标准库
#include <algorithm>  // 包含用于算法操作的头文件，如 transform 和 find
using namespace std;  // 使用标准命名空间

int n, m;  // n 是第一个单词列表的长度，m 是第二个单词列表的长度

// 转换字符串 s 为小写字母
void toLower(string &s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);  // 使用 transform 将字符串的每个字符转换为小写
}

int main()
{
    cin >> n >> m;  // 输入两个列表的长度 n 和 m
    vector<string> s1(n), s2(m);  // 定义两个字符串向量，用来存储两个单词列表
    set<string> all_words;  // 使用 set 存储所有的单词，自动去重
    int common = 0;  // 用于记录共同出现的单词数

    // 读取第一个单词列表，并将其所有单词转换为小写，存入 all_words
    for (int i = 0; i < n; i++) cin >> s1[i], toLower(s1[i]), all_words.insert(s1[i]);
    // 读取第二个单词列表，并将其所有单词转换为小写，存入 all_words
    for (int i = 0; i < m; i++) cin >> s2[i], toLower(s2[i]), all_words.insert(s2[i]);

    // 查找两个列表中共同的单词
    for (auto it: all_words)  // 遍历所有出现的单词
    {
        // 查找单词 it 是否出现在第一个列表 s1 和第二个列表 s2 中
        auto it1 = find(s1.begin(), s1.end(), it);
        auto it2 = find(s2.begin(), s2.end(), it);

        // 如果单词同时出现在两个列表中，增加共同单词数
        if (it1 != s1.end() && it2 != s2.end()) common++;
    }

    // 输出共同单词数和所有不同单词的数目
    cout << common << endl << all_words.size() << endl;
}


/*
【问题描述】

两个集合的 Jaccard 相似度定义为：

 A∩B

Sim(A, B) =

|A ∪B|

即交集的大小除以并集的大小。当集合 A 和 B 完全相同时，Sim(A, B) = 1 取得最大值；当二者交集为空时，Sim(A, B) = 0 取得最小值。

除了进行简单的词频统计，小 P 还希望使用 Jaccard 相似度来评估两篇文章的相似性。具体来说，每篇文章均由若干个英文单词组成，且英文单词仅包含“大小写英文字  母”。对于给定的两篇文章，小 P 首先需要提取出两者的单词集合 A 和 B，即去掉各自重复的单词。然后计算出：

• |A ∩ B|，即有多少个不同的单词同时出现在两篇文章中；

• |A ∪ B|，即两篇文章一共包含了多少个不同的单词。

最后再将两者相除即可算出相似度。需要注意，在整个计算过程中应当忽. 略. 英. 文. 字.

母. 大. 小. 写. 的区别，比如 the、The 和 THE 三者都应被视作同一个单词。

试编写程序帮助小 P 完成前两步，计算出 |A ∩ B| 和 |A ∪ B|；小 P 将亲自完成最后一步的除法运算。


【输出形式】

从标准输入读入数据。输入共三行。

输入的第一行包含两个正整数 n 和 m，分别表示两篇文章的单词个数。第二行包含空格分隔的 n 个单词，表示第一篇文章；

第三行包含空格分隔的 m 个单词，表示第二篇文章。

【输入形式】


输出到标准输出。输出共两行。

第一行输出一个整数 |A ∩ B|，即有多少个不同的单词同时出现在两篇文章中； 第二行输出一个整数 |A ∪ B|，即两篇文章一共包含了多少个不同的单词。



【样例 1 输入】
3 2
The tHe thE
the THE
【样例 1 输出】
 1
 1
【样例 2 输入】
9 7
Par les soirs bleus dete jirai dans les sentiers
PICOTE PAR LES BLES FOULER LHERBE MENUE
【样例 2 输出】
 2
 13
【样例 3 输入】
15 15
Thou that art now the worlds fresh ornament And only herald to the
gaudy spring
Shall I compare thee to a summers day Thou art more lovely and
more temperate
【样例 3 输出】
 4
 24
【样例说明】
【样例 1 解释】

A = B = A ∩ B = A ∪ B = {the}

【样例 2 解释】

    A = {bleus, dans, dete, jirai, les, par, sentiers, soirs} |A| = 8

    B = {bles, fouler, les, lherbe, menue, par, picote} |B| = 7

    A ∩ B = {les, par} |A ∩ B| = 2

【评分标准】

    80% 的测试数据满足：n, m ≤ 100 且所有字母均为小写；

    全部的测试数据满足：n, m ≤ 104  且每个单词最多包含 10 个字母。
 */
