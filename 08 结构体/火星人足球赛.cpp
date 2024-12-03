#include <bits/stdc++.h>
using namespace std;

// 定义犯规记录结构体
struct Foul {
    int time;     // 犯规时间
    int id;       // 球员编号
    bool isHome;  // 是否为主队球员：0为主队，1为客队
    bool redCard; // 是否已经获得红牌
};

int main() {
    // 读取主队和客队的队名
    string home, away;
    cin >> home >> away;

    int n; // 犯规次数
    cin >> n;

    vector<Foul> fouls(n); // 存储犯规记录

    // 处理每次犯规记录
    for (int i = 0; i < n; i++) {
        int t, pId;
        char team, card;

        cin >> t >> team >> pId >> card;

        fouls[i].time = t;
        fouls[i].id = pId;
        fouls[i].isHome = (team == 'h') ? 0 : 1; // 主队为0，客队为1
        fouls[i].redCard = (card == 'r'); // 红牌标记
    }

    // 记录黄牌次数
    unordered_map<int, int> yellowHome, yellowAway;
    vector<Foul> redCards; // 存储获得红牌的球员

    // 处理犯规记录，判断是否应当给红牌
    for (int i = 0; i < n; i++) {
        Foul &foul = fouls[i];

        // 如果已经是红牌，跳过
        if (foul.redCard) {
            redCards.push_back(foul);
            continue;
        }

        // 处理黄牌
        if (foul.isHome == 0) { // 主队
            yellowHome[foul.id]++;
            if (yellowHome[foul.id] == 2) {
                foul.redCard = true;
                redCards.push_back(foul);
            }
        } else { // 客队
            yellowAway[foul.id]++;
            if (yellowAway[foul.id] == 2) {
                foul.redCard = true;
                redCards.push_back(foul);
            }
        }
    }

    // 如果没有红牌，输出 "No Red Card"
    if (redCards.empty()) {
        cout << "No Red Card" << endl;
        return 0;
    }

    // 按照时间、球队和球员编号排序
    sort(redCards.begin(), redCards.end(), [](const Foul &a, const Foul &b) {
        if (a.time == b.time) {
            if (a.isHome == b.isHome) {
                return a.id > b.id; // 编号大的排前面
            }
            return a.isHome < b.isHome; // 主队排前面
        }
        return a.time < b.time; // 时间排序
    });

    // 输出红牌记录
    for (const Foul &foul : redCards) {
        cout << (foul.isHome == 0 ? home : away) << " "
             << foul.id << " " << foul.time << endl;
    }

    return 0;
}
/*
【问题描述】

       火星人足球赛的比赛规则与地球人的比赛规则有些非常相似，比如严重犯规，将被给予黄牌警告，特别严重的犯规，将给予红牌直接罚下，如果有人得到第2张黄牌，则自动获得红牌罚下，比赛同样采取主客场制。

       与地球人足球赛不同的是，火星人足球赛每队可以上场的人数不会固定为11人，可以多个人，比赛时间也会更长一些。

       比赛时的裁判员是机器人，判罚非常严厉，如果有人获得红黄牌，机器人裁判将自动记录当时的情况。

【输入形式】

       输入的第一行为主队队名，第二行为客队队名，队名的长度不超过20个字符。

       第三行为一个整数 n (0?≤?n?≤?90) ，表示得到红黄牌的犯规次数。

       接下来的n行，每行包含用空格分隔的4个部分，表示犯规的情况:

首先为一个整数，表示犯规的时间（分钟）

接着为一个字符"h"或"a"，如果为"h"，表示该张牌会给到主队球员，否则会给到客队球员

接下来为球员编号m  (1?≤?m?≤?99)

接下来为一个字符"y"或"r"，如果为"y"，表示为黄牌，否则为红牌

       不同球队的球员可能有相同的号码，在同一球队球员的号码不相同，犯规记录按时间顺序排列。

【输出形式】

       输出按时间顺序排列的获得红牌的记录，如果时间相同，则主队排在前面，如果同一时间同一球队有多人获得红牌，则编号大的排在前面。每个红牌一行，包含3个部分：球员所属球队的名字、犯规球员编号、获得红牌时间。

      如果全场比赛无红牌，输出"No Red Card"
【样例输入】

MC
CSKA
9
28 a 3 y
62 h 25 y
66 h 42 y
70 h 25 y
77 a 4 y
79 a 25 y
82 h 42 r
89 h 16 y
90 a 13 r
【样例输出】

MC 25 70
MC 42 82
CSKA 13 90
 */