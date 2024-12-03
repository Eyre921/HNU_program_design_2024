#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 定义一个结构体来存储科学家的语言
struct Scientist {
    int lang;  // 科学家熟悉的语言编号
};

// 定义一个结构体来存储电影的信息
struct Movie {
    int audioLang;  // 音频语言编号
    int subtitleLang;  // 字幕语言编号
    int happyCount = 0;  // 非常高兴的科学家数量
    int satisfiedCount = 0;  // 基本满意的科学家数量
};

int main() {
    int n, m;
    cin >> n;  // 输入科学家的数量

    // 存储科学家数据
    vector<Scientist> scientists(n);
    for (int i = 0; i < n; i++) {
        cin >> scientists[i].lang;  // 输入每个科学家的语言
    }

    cin >> m;  // 输入电影的数量

    // 存储电影数据
    vector<Movie> movies(m);

    // 输入电影的音频语言
    for (int i = 0; i < m; i++) {
        cin >> movies[i].audioLang;
    }

    // 输入电影的字幕语言
    for (int i = 0; i < m; i++) {
        cin >> movies[i].subtitleLang;
    }

    // 计算每部电影的“非常高兴”和“基本满意”的科学家数量
    for (const auto& sci : scientists) {
        for (auto& movie : movies) {
            if (sci.lang == movie.audioLang) {
                movie.happyCount++;  // 增加“非常高兴”计数
            }
            if (sci.lang == movie.subtitleLang) {
                movie.satisfiedCount++;  // 增加“基本满意”计数
            }
        }
    }

    // 如果所有电影都没有任何科学家“非常高兴”，输出 "unsatisfied"
    bool allUnsatisfied = true;
    for (const auto& movie : movies) {
        if (movie.happyCount > 0) {
            allUnsatisfied = false;
            break;
        }
    }

    if (allUnsatisfied) {
        cout << "unsatisfied";
    } else {
        // 找到最大“非常高兴”的人数
        int maxHappy = 0;
        for (const auto& movie : movies) {
            maxHappy = max(maxHappy, movie.happyCount);
        }

        // 找到在最大“非常高兴”人数中的最大“基本满意”人数
        int maxSatisfied = 0;
        for (const auto& movie : movies) {
            if (movie.happyCount == maxHappy) {
                maxSatisfied = max(maxSatisfied, movie.satisfiedCount);
            }
        }

        // 输出所有符合条件的电影编号（从1开始）
        bool found = false;
        for (int i = 0; i < m; i++) {
            if (movies[i].happyCount == maxHappy && movies[i].satisfiedCount == maxSatisfied) {
                cout << i + 1 << " ";  // 输出符合条件的电影编号
                found = true;
            }
        }

        // 如果没有找到符合条件的电影，输出"unsatisfied"
        if (!found) {
            cout << "unsatisfied";
        }
    }

    return 0;
}
/*
【问题描述】

       湖南大学正在举办一场重要的国际学术会议，出席会议的 n 位科学家来自不同的国家，每位科学家都只熟悉一种语言，为方便起见，世界上所有的语言用1~1000的数字编号来列出。

       晚上，主办方安排所有科学家去看电影，电影院里有 m 部电影，每部电影可以用两个不同的整数来描述，即音频语言和字幕语言的编号。看电影的科学家，如果他熟悉电影的音频语言，他会非常高兴，如果他熟悉字幕的语言，他基本上满意，如果他两种都不熟悉，他会感到不满意(请注意，每部电影的音频语言和字幕语言总是不同的)。

       科学家们决定一起去看同一部电影。你必须帮助他们选择电影，使得非常高兴的科学家的数量是最大的，如果有多部这样的电影，在其中选择能使基本满意的科学家的数量最大，如果还有多部，则全部输出。如果没有这样的电影，则输出"unsatisfied"。

【输入形式】

       输入的第一行为一个正整数 n (1 ≤ n ≤ 200000)  ，表示科学家的数量。

       第二行为 n 个正整数a1、a2、...、an (1 ≤ ai ≤ 1000)，其中ai 表示第 i 位科学家熟悉的语言编号。

       第三行包含一个正整数m(1 ≤ m ≤ 200000)，表示电影院里的电影数量，编号从1~m。

       第四行包含 m 个正整数 b1, b2, ..., bm (1 ≤ bj ≤ 1000)，其中 bj 表示第  j 部电影的音频语言。

        第五行包含 m 个正整数 c1, c2, ..., cm (1 ≤ cj ≤ 1000)，其中 cj 表示第  j 部电影的字幕语言。

         输入保证 bj ≠ cj  。

【输出形式】

       输出为若干整数，从小到大，表示科学家们可以去选择去看的电影的编号。如果没有这样的电影，则输出"unsatisfied"。

【样例输入】

3
2 3 2
2
3 2
2 3
【样例输出】

2
 */