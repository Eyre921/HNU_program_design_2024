#include <bits/stdc++.h>
using namespace std;

// 定义青蛙结构体
struct Frog {
    int position;       // 青蛙位置
    long long tongueLength; // 舌头长度
    int mosquitoesEaten;  // 吃掉的蚊子数量
    int originalIndex;    // 青蛙的原始编号
};

// 定义蚊子结构体
struct Mosquito {
    int position;       // 蚊子位置
    long long weight;   // 蚊子重量
};

bool compareFrogsByPosition(const Frog& a, const Frog& b) {
    return a.position < b.position;  // 按青蛙的位置排序
}

bool compareFrogsByOriginalIndex(const Frog& a, const Frog& b) {
    return a.originalIndex < b.originalIndex;  // 按原始编号排序
}

int main() {
    long long n, m;
    cin >> n >> m;

    vector<bool> mosquitoEaten(m, false);  // 标记蚊子是否已被吃掉
    vector<Frog> frogs(n);                 // 存储青蛙数据
    vector<Mosquito> mosquitoes(m);        // 存储蚊子数据

    // 输入青蛙数据
    for (int i = 0; i < n; i++) {
        cin >> frogs[i].position >> frogs[i].tongueLength;
        frogs[i].mosquitoesEaten = 0;
        frogs[i].originalIndex = i + 1;
    }

    // 输入蚊子数据
    for (int i = 0; i < m; i++) {
        cin >> mosquitoes[i].position >> mosquitoes[i].weight;
    }

    // 按青蛙位置排序
    sort(frogs.begin(), frogs.end(), compareFrogsByPosition);

    // 处理每一只蚊子
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (!mosquitoEaten[j] && frogs[i].position <= mosquitoes[j].position && frogs[i].position + frogs[i].tongueLength >= mosquitoes[j].position) {
                // 青蛙能吃掉蚊子
                frogs[i].tongueLength += mosquitoes[j].weight;  // 青蛙吃掉蚊子，舌头长度增加
                mosquitoEaten[j] = true;  // 标记蚊子已被吃掉
                frogs[i].mosquitoesEaten++;  // 增加青蛙吃的蚊子数量

                // 对当前青蛙，检查是否能吃掉其他蚊子
                for (int k = 0; k < j; k++) {
                    if (!mosquitoEaten[k] && frogs[i].position <= mosquitoes[k].position && frogs[i].position + frogs[i].tongueLength >= mosquitoes[k].position) {
                        frogs[i].tongueLength += mosquitoes[k].weight;  // 吃掉蚊子
                        mosquitoEaten[k] = true;  // 标记蚊子已被吃掉
                        frogs[i].mosquitoesEaten++;  // 增加青蛙吃的蚊子数量
                        k = -1;  // 重置k，重新检查所有蚊子
                    }
                }
                break;  // 一旦青蛙吃掉了蚊子，就可以跳出当前循环，处理下一只蚊子
            }
        }
    }

    // 按照青蛙的原始顺序输出结果
    sort(frogs.begin(), frogs.end(), compareFrogsByOriginalIndex);
    for (const Frog& frog : frogs) {
        cout << frog.mosquitoesEaten << " " << frog.tongueLength << endl;
    }

    return 0;
}
/*
【问题描述】

       有 n 只青蛙位于坐标轴 OX 上，对于每只青蛙，有两个已知值 xi、ti，表示第 i 只青蛙在坐标的位置（各不相同）以及它的舌头的长度。同样有 m 只蚊子一只接一只的落到坐标轴上，对于每只蚊子，有两个已知值， pj 表示第 j 只蚊子所在的位置，bj 为第 j 只蚊子的重量。青蛙和蚊子表示为坐标上的点。

       如果蚊子和青蛙在同一位置或者在右边，青蛙可以吃掉蚊子，它们之间的距离不超过青蛙舌头的长度。

       如果有几只青蛙都能在某一时刻吃到一只蚊子，最左边的青蛙就会吃掉它（最小的 xi）。吃完蚊子后，青蛙的舌头将增加蚊子重量的长度，在之后，青蛙又能够吃其他蚊子(在舌头长度增加之后)。

       在所有蚊子落下以及青蛙吃掉所有可能的蚊子之后，对于每个青蛙，输出两个值，即吃蚊子的数量以及舌头的长度。

       每只蚊子只有在青蛙吃完之前所有可能的蚊子之后才会落到坐标上，蚊子的值是按其落到坐标轴上的顺序给出的。

【输入形式】

       输入的第一行为两个整数(1 ≤ n，m ≤ 2*105），表示青蛙和蚊子的数量。

       接下来的 n 行，每行两个整数 xi、ti（0 ≤ xi、ti ≤ 109），表示第 i 只青蛙所在的位置以及它的舌头的初始长度，输入保证所有的 xi 互不相同。

       接下来的 m 行，每行两个整数 pj、bj（0 ≤ pj、bj ≤ 109），表示第 j 只蚊子落下的位置以及它的重量。

【输出形式】

       输出为 n 行，第 i 行包含另两个整数值 ci、li，表示被第 i 只青蛙吃掉的蚊子数量以及最终的青蛙的舌头长度。
【样例输入1】

4 6
10 2
15 0
6 1
0 1
110 10
1 1
6 0
15 10
14 100
12 2
【样例输出1】

3 114
1 10
1 1
1 2
【样例输入2】

1 2
10 2
20 2
12 1
【样例输出2】

1 3
 */