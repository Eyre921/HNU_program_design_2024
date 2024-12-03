#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef unsigned short us;  // 为了简化书写，将 unsigned short 重定义为 us

// 洗牌函数声明
void shuffle(us *card);

// 交换两张牌的函数声明
void swapCard(us *a, us *b);

// 切牌函数声明
void cut(us card[]);

// 发牌函数声明
void deal(us player[][13], us card[]);

// 整理牌的函数声明
void reorder(us (*p)[13]);

// 冒泡排序函数声明
void buble(us a[], int n);

// 转换牌面值的函数声明
us convert(us b);

// 显示玩家手牌的函数声明
void display(us player[][13]);

int main() {
    us player[4][13];  // 表示4个玩家，每个玩家13张牌
    us card[53];       // 用于存储一副牌，1~13代表黑桃S、14~26代表红心H、27~39代表方片D、40~52代表梅花C

    shuffle(card);     // 洗牌
    cut(card);         // 切牌
    deal(player, card); // 发牌
    reorder(player);   // 整理牌
    display(player);   // 显示牌面

    return 0;
}

// 洗牌函数
void shuffle(us card[]) {
    srand(time(NULL));  // 使用当前时间作为随机数种子
    int loc1, loc2;

    // 初始化牌
    for (int i = 1; i <= 52; i++)
        card[i] = i;

    // 洗牌过程
    for (int i = 1; i <= 52; i++) {
        while (!(loc1 = rand() % 53));  // 随机生成loc1
        while (!(loc2 = rand() % 53));  // 随机生成loc2

        if (loc1 == loc2)  // 如果loc1和loc2相同，调整loc2
            loc2 = loc1 + 1;

        if (loc2 == 53)  // 如果loc2超出范围，设置为1
            loc2 = 1;

        swapCard(&card[loc1], &card[loc2]);  // 交换牌面
    }
}

// 交换两张牌的函数
void swapCard(us *a, us *b) {
    us tmp = *a;  // 使用中间变量tmp交换a和b的值
    *a = *b;
    *b = tmp;
}

// 切牌函数
void cut(us card[]) {
    int loc;
    srand(time(NULL));

    while (!(loc = rand() % 52));  // 随机选择切牌位置

    us *p = new us[loc + 1];  // 动态分配数组存储切掉的牌

    // 保存切掉的牌
    for (int i = 1; i <= loc; i++) {
        p[i] = card[i];
    }

    // 将剩余的牌向前移动
    for (int i = loc + 1; i <= 52; i++) {
        card[i - loc] = card[i];
    }

    // 将切掉的牌放到后面
    for (int i = 1; i <= loc; i++) {
        card[52 - loc + i] = p[i];
    }

    delete[] p;  // 删除动态数组
}

// 发牌函数
void deal(us player[][13], us card[]) {
    us (*p)[13] = player;
    unsigned int j = 0, k = 0;
    us *start;

    // 将卡片分发给玩家
    for (int i = 1; i <= 52; i++) {
        start = *(p + k);  // 获取玩家手牌
        start[j] = card[i]; // 分发牌
        if (k == 3) {  // 如果已发完一轮，转到下一个玩家
            k = 0;
            j++;
        } else {
            k++;
        }
    }
}

// 整理手牌函数，按牌面值进行排序
void reorder(us (*p)[13]) {
    for (int i = 0; i < 4; i++) {
        buble(*p, 13);  // 对每个玩家的13张牌进行排序
        p++;  // 指向下一个玩家
    }
}

// 冒泡排序函数
void buble(us a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (convert(a[j]) > convert(a[j + 1])) {
                // 交换两张牌的顺序
                unsigned int tmp;
                tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
}

// 转换牌面值函数
us convert(us b) {
    if (b % 13 == 1)  // 如果是A牌，转换为14
        return 14;

    if (b < 14)  // 黑桃S
        return b;
    else if (b < 27)  // 红心H
        return b - 13;
    else if (b < 40)  // 方片D
        return b - 26;
    else  // 梅花C
        return b - 39;
}

// 显示玩家手牌函数
void display(us player[][13]) {
    char *face[14] = {NULL, "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

    for (int i = 0; i < 4; i++) {  // 对每个玩家的手牌进行输出
        for (int j = 0; j < 13; j++) {
            // 根据牌的编号，输出花色
            if (player[i][j] < 14)
                cout << "S";  // 黑桃
            else if (player[i][j] < 27)
                cout << "H";  // 红心
            else if (player[i][j] < 40)
                cout << "D";  // 方片
            else
                cout << "C";  // 梅花

            int point = convert(player[i][j]);
            if (point == 14)
                point = 1;  // A牌的转换值为14，显示为1
            cout << "(" << face[point] << ") ";  // 输出牌面值
        }
        cout << endl;  // 每个玩家一行
    }
}
